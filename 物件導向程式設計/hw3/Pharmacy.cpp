/*
Pharmacy.cpp
藥劑室管理類實現檔

- 在建構子中初始化5種藥物及其價格
- 選擇範圍：1-5（對應數組索引 0-4）
- applyMedication() 將藥物費用直接添加到患者帳戶的charges中
*/

#include "Pharmacy.h"
#include <iostream>
#include <iomanip>

using namespace std;

// 建構子：初始化5種藥物類型及其價格
// 藥物類型：青黴素、阿斯匹林、維生素C、感冒藥、高血壓藥
Pharmacy::Pharmacy()
{
    medications[0] = {"青黴素", 100.0};
    medications[1] = {"阿斯匹林", 50.0};
    medications[2] = {"維生素C", 75.0};
    medications[3] = {"感冒藥", 120.0};
    medications[4] = {"高血壓藥", 200.0};
}

// 顯示藥物菜單：列出所有可用的藥物選項和價格
void Pharmacy::displayPharmacyMenu() const
{
    cout << "\n========== 藥物菜單 ==========" << endl;
    for (int i = 0; i < NUM_MEDICATIONS; i++)
        cout << (i + 1) << ". " << medications[i].medicationName << " - $" << fixed << setprecision(2) << medications[i].price << endl;

    cout << "==============================" << endl
         << endl;
}

// 根據使用者選擇（1-5）取得藥物價格
// 若選擇無效則返回 0.0
double Pharmacy::getMedicationPrice(int choice) const
{
    if (choice >= 1 && choice <= NUM_MEDICATIONS)
        return medications[choice - 1].price;
    return 0.0;
}

// 根據使用者選擇（1-5）取得藥物名稱
// 若選擇無效則返回 "未知藥物"
string Pharmacy::getMedicationName(int choice) const
{
    if (choice >= 1 && choice <= NUM_MEDICATIONS)
        return medications[choice - 1].medicationName;
    return "未知藥物";
}

// 應用藥物到患者帳戶：驗證選擇、取得價格並添加到患者的charges
void Pharmacy::applyMedication(PatientAccount &patient, int medicationChoice)
{
    double price = getMedicationPrice(medicationChoice);
    // 價格有效，添加到患者帳戶
    if (price > 0)
    {
        patient.addCharges(price);
        cout << "已添加藥物費用: " << getMedicationName(medicationChoice) << " - $" << fixed << setprecision(2) << price << endl;
    }
    // 價格無效，顯示錯誤信息
    else
        cout << "無效的藥物選擇。" << endl;
}
