#ifndef QUOTE_SYSTEM_CORE_H
#define QUOTE_SYSTEM_CORE_H

#include <string>
#include <vector>

// 字串處理工具：去除 \t、\r、\n (Tab、回車、換行)
std::string trim(const std::string &text);

// 大小寫轉換 固定轉換成小寫
std::string toLowerAscii(std::string text);

// 檢查 source 是否包含 keyword（不分大小寫）
bool containsText(const std::string &source, const std::string &keyword);

// 安全讀取輸入：一行輸入 並可以選擇是否允許空字串(關鍵字查詢)
std::string promptLine(const std::string &prompt, bool allowEmpty = false);

// 安全讀取整數輸入 並限制範圍(選功能、年份輸入、刪除)
int promptInt(const std::string &prompt, int minValue, int maxValue);

// 安全讀取浮點數輸入 並限制最小值(金額、稅率)
double promptDouble(const std::string &prompt, double minValue);

// 估價單結構 定義所有必要欄位與計算方
struct ServiceQuote
{
    int quoteId = 0;
    std::string customerName;
    std::string customerTitle;
    std::string quoteDate;
    std::string vehicleMake;
    std::string vehicleModel;
    int vehicleYear = 0;
    std::string serviceDescription;
    double partsCharge = 0.0;
    double laborCharge = 0.0;
    double taxRate = 0.0;

    double subtotal() const;
    double taxAmount() const;
    double totalAmount() const;
    bool matchesKeyword(const std::string &keyword) const;
    void displaySummary() const;
};

// 估價單管理器
class QuoteManager
{
private:
    std::vector<ServiceQuote> quotes;
    int nextQuoteId = 1;

public:
    int addQuote(ServiceQuote quote);
    bool deleteQuoteById(int quoteId);
    std::vector<const ServiceQuote *> searchQuotes(const std::string &keyword) const;
    const std::vector<ServiceQuote> &getAllQuotes() const;
    bool empty() const;
};

#endif