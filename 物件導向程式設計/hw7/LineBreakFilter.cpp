#include "LineBreakFilter.h"

#include <stdexcept>

using namespace std;

// 將換行符轉為空格的簡單實作

char LineBreakFilter::transform(char ch)
{
    if (ch == '\r' || ch == '\n')
        return ' ';
    return ch;
}

// doFilter 的實作：每個換行輸出一個空白（CRLF 視為單一換行）
void LineBreakFilter::doFilter(ifstream &in, ofstream &out)
{
    if (!in)
        throw runtime_error("input stream not open");
    if (!out)
        throw runtime_error("output stream not open");

    char ch;
    while (in.get(ch))
    {
        if (ch == '\r')
        {
            // 處理 CRLF：若下一個是 \n，吃掉後輸出一個空格
            if (in.peek() == '\n')
                in.get();
            out.put(' ');
        }
        else if (ch == '\n')
        {
            out.put(' ');
        }
        else
        {
            out.put(transform(ch));
        }

        if (!out)
            throw runtime_error("寫入輸出檔時發生錯誤");
    }

    if (in.bad())
        throw runtime_error("讀取輸入檔時發生錯誤");

    out.flush();
    if (!out)
        throw runtime_error("輸出檔刷新失敗");
}
