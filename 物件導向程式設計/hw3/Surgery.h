/*
Surgery.h
手術管理類定義檔

- 管理醫院提供的各類手術和其費用
- 提供手術菜單供使用者選擇
- 對患者帳戶添加手術費用
*/

#ifndef SURGERY_H
#define SURGERY_H

#include "PatientAccount.h"
#include <string>

// 手術資訊結構體：存儲手術名稱和費用
struct SurgeryType
{
    std::string surgeryName;
    double cost;
};

class Surgery
{
private:
    SurgeryType surgeries[5];

public:
    // 建構子：初始化5種手術及其費用
    Surgery();

    // 菜單和查詢函式
    void displaySurgeryMenu() const;
    double getSurgeryCost(int choice) const;
    std::string getSurgeryName(int choice) const;

    // 應用手術到患者帳戶（自動添加費用）
    void applySurgery(PatientAccount &patient, int surgeryChoice);
};

#endif