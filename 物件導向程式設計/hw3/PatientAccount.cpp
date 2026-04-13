/*
PatientAccount.cpp
患者帳戶類實現檔

- dailyRate 是靜態成員，對所有PatientAccount對象共享
- charges 存儲所有費用的總和（手術、藥物、住院費）
- 住院費 = daysInHospital * dailyRate，在 calculateHospitalCharges() 時計算
*/

#include "PatientAccount.h"
#include <iostream>
#include <iomanip>

using namespace std;

// 靜態成員初始化：每日醫院費率為500元
double PatientAccount::dailyRate = 500.0;

// 預設建構子：初始化所有成員變數
PatientAccount::PatientAccount()
    : patientName(""), patientId(""), daysInHospital(0), charges(0.0)
{
}

// 帶參數建構子：初始化患者姓名和ID
PatientAccount::PatientAccount(string name, string id)
    : patientName(name), patientId(id), daysInHospital(0), charges(0.0)
{
}

// 設置患者姓名
void PatientAccount::setPatientName(string name)
{
    patientName = name;
}

// 設置患者ID
void PatientAccount::setPatientId(string id)
{
    patientId = id;
}

// 設置住院天數
void PatientAccount::setDaysInHospital(int days)
{
    daysInHospital = days;
}

// 設置每日費率（靜態函式，影響所有患者）
void PatientAccount::setDailyRate(double rate)
{
    PatientAccount::dailyRate = rate;
}

// 取得患者姓名
string PatientAccount::getPatientName() const
{
    return patientName;
}

// 取得患者ID
string PatientAccount::getPatientId() const
{
    return patientId;
}

// 取得住院天數
int PatientAccount::getDaysInHospital() const
{
    return daysInHospital;
}

// 取得每日費率
double PatientAccount::getDailyRate() const
{
    return dailyRate;
}

// 添加費用（用於手術費、藥物費等）
void PatientAccount::addCharges(double amount)
{
    charges += amount;
}

// 計算住院費：住院天數 × 每日費率，加入總費用
void PatientAccount::calculateHospitalCharges()
{
    charges += daysInHospital * dailyRate;
}

// 取得總費用
double PatientAccount::getTotalCharges() const
{
    return charges;
}

// 取得當前累計費用（同 getTotalCharges，提供兩個接口以增加靈活性）
double PatientAccount::getCharges() const
{
    return charges;
}

// 顯示患者帳單
void PatientAccount::displayBill() const
{
    cout << "\n========================================" << endl;
    cout << "           患者帳單" << endl;
    cout << "========================================" << endl;
    cout << "患者姓名: " << patientName << endl;
    cout << "患者ID:   " << patientId << endl;
    cout << "住院天數: " << daysInHospital << " 天" << endl;
    cout << "每日費率: $" << fixed << setprecision(2) << dailyRate << endl;
    cout << "住院費:   $" << fixed << setprecision(2) << (daysInHospital * dailyRate) << endl;
    cout << "其他費用: $" << fixed << setprecision(2) << (charges - daysInHospital * dailyRate) << endl;
    cout << "----------------------------------------" << endl;
    cout << "總費用:   $" << fixed << setprecision(2) << charges << endl;
    cout << "========================================\n"
         << endl;
}
