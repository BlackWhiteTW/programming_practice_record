/*
Surgery.cpp
手術管理類實現檔

- 在建構子中初始化5種手術及其費用
- 選擇範圍：1-5（對應數組索引 0-4）
- applySurgery() 將手術費用直接添加到患者帳戶的charges中
*/

#include "Surgery.h"
#include <iostream>
#include <iomanip>

using namespace std;

// 建構子：初始化5種手術類型及其费用
// 手術類型：一般、心臟、眼科、骨科、神經外科
Surgery::Surgery()
{
    surgeries[0] = {"一般手術", 5000.0};
    surgeries[1] = {"心臟手術", 15000.0};
    surgeries[2] = {"眼科手術", 8000.0};
    surgeries[3] = {"骨科手術", 10000.0};
    surgeries[4] = {"神經外科手術", 18000.0};
}

// 顯示手術菜單：列出所有可用的手術選項和費用
void Surgery::displaySurgeryMenu() const
{
    cout << "\n========== 手術菜單 ==========" << endl;
    for (int i = 0; i < NUM_SURGERIES; i++)
        cout << (i + 1) << ". " << surgeries[i].surgeryName << " - $" << fixed << setprecision(2) << surgeries[i].cost << endl;
    cout << "==============================" << endl
         << endl;
}

// 根據使用者選擇（1-5）取得手術費用
// 若選擇無效則返回 0.0
double Surgery::getSurgeryCost(int choice) const
{
    if (choice >= 1 && choice <= NUM_SURGERIES)
        return surgeries[choice - 1].cost;
    return 0.0;
}

// 根據使用者選擇（1-5）取得手術名稱
// 若選擇無效則返回 "未知手術"
string Surgery::getSurgeryName(int choice) const
{
    if (choice >= 1 && choice <= NUM_SURGERIES)
        return surgeries[choice - 1].surgeryName;
    return "未知手術";
}

// 應用手術到患者帳戶：驗證選擇、取得費用並添加到患者的charges
void Surgery::applySurgery(PatientAccount &patient, int surgeryChoice)
{
    double cost = getSurgeryCost(surgeryChoice);
    // 費用有效，添加到患者帳戶
    if (cost > 0)
    {
        patient.addCharges(cost);
        cout << "已添加手術費用: " << getSurgeryName(surgeryChoice) << " - $" << fixed << setprecision(2) << cost << endl;
    }
    // 費用無效，顯示錯誤信息
    else
        cout << "無效的手術選擇。" << endl;
}