#include "QuoteSystemUI.h"

#include <climits>
#include <iomanip>
#include <iostream>

using namespace std;

int main()
{
    // QuoteManager 負責維護所有估價單資料 為結構型態和功能核心
    QuoteManager manager;

    // 系統開場說明
    cout << "========== 汽車維修估價單管理系統 ==========" << endl;
    cout << "問題領域：manager 管理客戶的維修估價單能新增、查詢、刪除與瀏覽估價單" << endl;
    cout << "查詢時可使用客戶姓名或估價單日期作為關鍵字" << endl;

    // 主迴圈：直到使用者選擇離開才結束
    while (true)
    {
        // 每次迴圈先顯示選單再讀取功能代號
        printMenu();
        int choice = promptInt("請選擇功能（1-5）：", 1, 5);

        // 功能 1：新增估價單
        if (choice == 1)
        {
            // 收集輸入資料
            ServiceQuote quote = createQuoteFromInput();

            // 寫入管理器並取得系統編號
            int quoteId = manager.addQuote(quote);

            // 回饋新增結果與總估價
            cout << "已新增估價單編號為：" << quoteId << endl;
            cout << "總估價金額：$" << fixed << setprecision(2) << quote.totalAmount() << endl;
        }
        // 功能 2：關鍵字查詢（客戶姓名 / 日期）
        else if (choice == 2)
        {
            string keyword = promptLine("請輸入查詢關鍵字（客戶姓名或估價單日期）：");

            // 執行查詢並顯示結果
            vector<const ServiceQuote *> results = manager.searchQuotes(keyword);
            printQuotes(results);
        }
        // 功能 3：刪除估價單（依編號）
        else if (choice == 3)
        {
            // 若目前沒有資料可刪除直接提示並回到主選單
            if (manager.empty())
            {
                cout << "目前沒有可刪除的估價單" << endl;
                continue;
            }

            // 先列出目前清單讓使用者確認要刪哪一筆
            printAllQuotes(manager.getAllQuotes());

            // 讀取欲刪除編號後執行刪除
            int quoteId = promptInt("請輸入要刪除的估價單編號：", 1, INT_MAX);
            if (manager.deleteQuoteById(quoteId))
                cout << "估價單已刪除" << endl;
            else
                cout << "找不到指定編號的估價單" << endl;
        }
        // 功能 4：顯示全部估價單
        else if (choice == 4)
        {
            printAllQuotes(manager.getAllQuotes());
        }
        // 功能 5：離開程式
        else
        {
            cout << "系統結束" << endl;
            break;
        }
    }

    // 正常結束
    return 0;
}
