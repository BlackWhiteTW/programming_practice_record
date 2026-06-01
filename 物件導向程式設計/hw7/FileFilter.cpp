#include "FileFilter.h"

#include <cctype>
#include <stdexcept>

using namespace std;

// 檔案篩選的共通處理：逐字元讀取、轉換、寫回
// 若遇到 IO 錯誤會以例外拋出，呼叫端可捕捉處理（例如移除不完整輸出檔）
void FileFilter::doFilter(ifstream &in, ofstream &out)
{
    if (!in)
        throw runtime_error("input stream not open");
    if (!out)
        throw runtime_error("output stream not open");

    char ch;
    while (in.get(ch))
    {
        // 呼叫子類實作的 transform
        out.put(transform(ch));
        if (!out)
        {
            throw runtime_error("寫入輸出檔時發生錯誤");
        }
    }

    // 檢查是否有讀取錯誤
    if (in.bad())
    {
        throw runtime_error("讀取輸入檔時發生錯誤");
    }

    out.flush();
    if (!out)
    {
        throw runtime_error("輸出檔刷新失敗");
    }
}

// CopyFilter: 不改變任何 byte
char CopyFilter::transform(char ch)
{
    return ch;
}

// UppercaseFilter: 對 ASCII 英文字元做大寫化
char UppercaseFilter::transform(char ch)
{
    return static_cast<char>(toupper(static_cast<unsigned char>(ch)));
}

// EncryptionFilter: 建構時傳入 key（位移量），僅對 A-Z / a-z 做循環位移
EncryptionFilter::EncryptionFilter(int key) : key_(key)
{
    key_ = ((key_ % 26) + 26) % 26;
}

char EncryptionFilter::transform(char ch)
{
    unsigned char uch = static_cast<unsigned char>(ch);
    if (isupper(uch))
    {
        return static_cast<char>('A' + (uch - 'A' + key_) % 26);
    }
    else if (islower(uch))
    {
        return static_cast<char>('a' + (uch - 'a' + key_) % 26);
    }
    // 非英文字元不變
    return ch;
}
