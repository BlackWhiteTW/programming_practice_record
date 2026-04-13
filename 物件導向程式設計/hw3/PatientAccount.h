/*
PatientAccount.h
患者帳戶類定義檔

- 管理單一患者的基本資料 (姓名、ID)
- 記錄患者的住院相關费用
- 維護靜態的醫院日均費率 (對所有患者統一)
- 計算和顯示患者的最終退院帳單
*/

#ifndef PATIENT_ACCOUNT_H
#define PATIENT_ACCOUNT_H

#include <string>

class PatientAccount
{
private:
    // 姓名 ID 天數 費用 費率
    std::string patientName;
    std::string patientId;
    int daysInHospital;
    double charges;
    static double dailyRate;

public:
    // 預設和帶參數
    PatientAccount();
    PatientAccount(std::string name, std::string id);

    // 設置患者資料
    void setPatientName(std::string name);
    void setPatientId(std::string id);
    void setDaysInHospital(int days);
    void setDailyRate(double rate);

    // 取得患者資料
    std::string getPatientName() const;
    std::string getPatientId() const;
    int getDaysInHospital() const;
    double getDailyRate() const;

    // 費用管理
    void addCharges(double amount);
    void calculateHospitalCharges();
    double getTotalCharges() const;
    double getCharges() const;
    void displayBill() const;
};

#endif
