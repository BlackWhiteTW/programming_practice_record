#include "QuoteSystemCore.h"

#include <algorithm>
#include <cctype>
#include <iomanip>
#include <iostream>

using namespace std;

// 字串處理工具：去除 \t、\r、\n (Tab、回車、換行)
// 例如「 王小明 」會被整理成「王小明」
string trim(const string &text)
{
    size_t start = text.find_first_not_of(" \t\r\n");
    if (start == string::npos)
        return "";
    size_t end = text.find_last_not_of(" \t\r\n");
    return text.substr(start, end - start + 1);
}

// 大小寫轉換 固定轉換成小寫
// 注意：這裡是英文大小寫處理 中文不會改變 因此不建議輸入中文
string toLowerAscii(string text)
{
    transform(text.begin(), text.end(), text.begin(), [](unsigned char ch)
              { return static_cast<char>(tolower(ch)); });
    return text;
}

// 判斷 source 是否包含 keyword（不分大小寫）
// 若 keyword 是空字串 視為「全部符合」
bool containsText(const string &source, const string &keyword)
{
    if (keyword.empty())
        return true;
    return toLowerAscii(source).find(toLowerAscii(keyword)) != string::npos;
}

// 安全讀取輸入：一行輸入 並可以選擇是否允許空字串(關鍵字查詢)
// allowEmpty = false 時 會強制使用者輸入非空內容
string promptLine(const string &prompt, bool allowEmpty)
{
    while (true)
    {
        cout << prompt;

        string input;
        getline(cin, input);

        input = trim(input);

        // 若允許空字串 或者輸入非空 就回傳輸入內容
        if (allowEmpty || !input.empty())
            return input;

        cout << "輸入不可為空 請重新輸入" << endl;
    }
}

// 安全讀取整數輸入 並限制範圍(選功能、年份輸入、刪除)
// 透過 stoi + consumed 確保整串都是有效整數
int promptInt(const string &prompt, int minValue, int maxValue)
{
    while (true)
    {
        string input = promptLine(prompt);
        try
        {
            size_t consumed = 0;
            int value = stoi(input, &consumed);

            // 若 consumed != input.size() 代表後面還有非數字字元
            if (consumed != input.size())
                throw invalid_argument("extra characters");

            // 範圍檢查
            if (value < minValue || value > maxValue)
                throw out_of_range("out of range");

            return value;
        }
        catch (...)
        {
            // 任一錯誤都回到迴圈重新輸入
            cout << "請輸入介於 " << minValue << " 到 " << maxValue << " 的整數" << endl;
        }
    }
}

// 安全讀取浮點數輸入 並限制最小值(金額、稅率)
double promptDouble(const string &prompt, double minValue)
{
    while (true)
    {
        string input = promptLine(prompt);
        try
        {
            size_t consumed = 0;
            double value = stod(input, &consumed);

            // 驗證整串字元都被成功解析
            if (consumed != input.size())
                throw invalid_argument("extra characters");

            if (value < minValue)
                throw out_of_range("out of range");

            return value;
        }
        catch (...)
        {
            // 失敗就重新輸入
            cout << "請輸入大於等於 " << fixed << setprecision(2) << minValue << " 的數字" << endl;
        }
    }
}

// 小計 = 零件費 + 工資
double ServiceQuote::subtotal() const
{
    return partsCharge + laborCharge;
}

// 稅金 = 小計 * 稅率
// 這裡 taxRate 以百分比儲存（例如 5 代表 5%）
double ServiceQuote::taxAmount() const
{
    return subtotal() * taxRate / 100.0;
}

// 總價 = 小計 + 稅金
double ServiceQuote::totalAmount() const
{
    return subtotal() + taxAmount();
}

// 查詢規則：只要客戶姓名或日期任一欄位符合關鍵字就算命中
bool ServiceQuote::matchesKeyword(const string &keyword) const
{
    return containsText(customerName, keyword) || containsText(quoteDate, keyword);
}

// 輸出單張估價單摘要
// 這是所有列表顯示的共用格式
void ServiceQuote::displaySummary() const
{
    cout << "[估價單編號] " << quoteId << endl;
    cout << "  客戶姓名：" << customerName << endl;
    cout << "  稱謂/職稱：" << customerTitle << endl;
    cout << "  日期：" << quoteDate << endl;
    cout << "  車輛：" << vehicleYear << " " << vehicleMake << " " << vehicleModel << endl;
    cout << "  服務內容：" << serviceDescription << endl;
    cout << "  零件費：$" << fixed << setprecision(2) << partsCharge << endl;
    cout << "  工資：$" << fixed << setprecision(2) << laborCharge << endl;
    cout << "  稅率：" << fixed << setprecision(2) << taxRate << "%" << endl;
    cout << "  稅金：$" << fixed << setprecision(2) << taxAmount() << endl;
    cout << "  總估價：$" << fixed << setprecision(2) << totalAmount() << endl;
}

// 新增估價單：系統自動填入遞增編號
int QuoteManager::addQuote(ServiceQuote quote)
{
    quote.quoteId = nextQuoteId++;
    quotes.push_back(quote);
    return quote.quoteId;
}

// 依估價單編號刪除
// 成功刪除回傳 true；找不到則 false
bool QuoteManager::deleteQuoteById(int quoteId)
{
    // remove_if 會把「要刪除」元素移到尾端 回傳第一個待刪位置
    auto it = remove_if(quotes.begin(), quotes.end(), [quoteId](const ServiceQuote &quote)
                        { return quote.quoteId == quoteId; });

    // 沒有任何元素符合刪除條件
    if (it == quotes.end())
        return false;

    // 真正從容器移除尾端待刪元素
    quotes.erase(it, quotes.end());
    return true;
}

// 依關鍵字查詢所有符合估價單
// 回傳指標清單 讓呼叫端可直接讀取原始資料內容
vector<const ServiceQuote *> QuoteManager::searchQuotes(const string &keyword) const
{
    vector<const ServiceQuote *> result;

    // 線性掃描所有估價單 逐筆判斷是否命中關鍵字
    for (const auto &quote : quotes)
        if (quote.matchesKeyword(keyword))
            result.push_back(&quote);

    return result;
}

// 提供全部估價單唯讀存取
const vector<ServiceQuote> &QuoteManager::getAllQuotes() const
{
    return quotes;
}

// 判斷目前是否沒有任何估價單
bool QuoteManager::empty() const
{
    return quotes.empty();
}