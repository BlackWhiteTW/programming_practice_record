#include "QuoteSystemUI.h"

#include <iostream>

using namespace std;

// 顯示主選單
// 單純輸出選項說明 顯示 5 個功能選項
void printMenu()
{
    cout << "\n========== 汽車維修估價單管理系統 ==========" << endl;
    cout << "1. 新增估價單" << endl;
    cout << "2. 查詢估價單" << endl;
    cout << "3. 刪除估價單" << endl;
    cout << "4. 顯示所有估價單" << endl;
    cout << "5. 離開" << endl;
    cout << "==========================================" << endl;
}

// 創建估價單物件
// 逐欄位向使用者收集估價單資料 所有輸入驗證交由 Core 的 prompt 系列函式處理
ServiceQuote createQuoteFromInput()
{
    ServiceQuote quote;

    // 客戶與日期資訊
    quote.customerName = promptLine("請輸入客戶姓名：");
    quote.customerTitle = promptLine("請輸入客戶稱謂或職稱（例如 先生、小姐、經理）：");
    quote.quoteDate = promptLine("請輸入估價單日期（例如 2026-04-26）：");

    // 車輛基本資料
    quote.vehicleYear = promptInt("請輸入車輛年份：", 1886, 9999);
    quote.vehicleMake = promptLine("請輸入車輛品牌：");
    quote.vehicleModel = promptLine("請輸入車輛型號：");

    // 維修描述與金額資料
    quote.serviceDescription = promptLine("請輸入服務內容：");
    quote.partsCharge = promptDouble("請輸入零件費：$", 0.0);
    quote.laborCharge = promptDouble("請輸入工資：$", 0.0);
    quote.taxRate = promptDouble("請輸入稅率（百分比例如 5 代表 5%）：", 0.0);

    return quote;
}

// 顯示查詢結果
// quotes 來源是 searchQuotes 的回傳值
void printQuotes(const vector<const ServiceQuote *> &quotes)
{
    cout << "\n========== 查詢結果 ==========" << endl;

    // 若沒有任何符合結果 直接輸出提示訊息
    if (quotes.empty())
    {
        cout << "查無符合條件的估價單" << endl;
        return;
    }

    // 逐筆輸出查詢到的 使用 ServiceQuote 內建摘要格式
    for (const auto *quote : quotes)
    {
        quote->displaySummary();
        cout << "------------------------------------------" << endl;
    }
}

// 顯示全部估價單
// 與 printQuotes 差異在於輸入資料型態是完整 vector<ServiceQuote> 而非指標清單
void printAllQuotes(const vector<ServiceQuote> &quotes)
{
    cout << "\n========== 所有估價單 ==========" << endl;

    // 無資料時回覆提示訊息
    if (quotes.empty())
    {
        cout << "目前沒有任何估價單" << endl;
        return;
    }

    // 逐筆列印摘要
    for (const auto &quote : quotes)
    {
        quote.displaySummary();
        cout << "------------------------------------------" << endl;
    }
}