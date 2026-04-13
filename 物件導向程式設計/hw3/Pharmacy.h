/*
Pharmacy.h
藥劑室管理類定義檔

- 管理醫院提供的各類藥物和其價格
- 提供藥物菜單供使用者選擇
- 對患者帳戶添加藥物費用
*/

#ifndef PHARMACY_H
#define PHARMACY_H

#include "PatientAccount.h"
#include <string>

// 藥物資訊結構體：存儲藥物名稱和價格
struct MedicationType
{
    std::string medicationName;
    double price;
};

class Pharmacy
{
private:
    MedicationType medications[5];

public:
    // 建構子：初始化5種藥物及其價格
    Pharmacy();

    // 菜單和查詢函式
    void displayPharmacyMenu() const;
    double getMedicationPrice(int choice) const;
    std::string getMedicationName(int choice) const;

    // 應用藥物到患者帳戶（自動添加費用）
    void applyMedication(PatientAccount &patient, int medicationChoice);
};

#endif