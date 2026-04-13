/*
main.cpp
醫院患者費用管理系統 - 主程式

學號 姓名：1454033 陳其佑
負責部份：1人製作(沒找到人)
開發中遇到的問題 & 解決方案：(個人)
1. 不熟悉專案的操作 在製作上花費了過多的時間
2. .cpp 和 .h 檔案的管理原本不太了解 在製作時才逐漸熟悉
*/

#include <bits/stdc++.h>
#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"

using namespace std;

// 顯示主菜單選項
void displayMainMenu()
{
    cout << endl
         << "========== 醫院患者費用管理系統 ==========" << endl;
    cout << "1. 添加手術費用" << endl;
    cout << "2. 添加藥物費用" << endl;
    cout << "3. 設置住院天數" << endl;
    cout << "4. 查看目前費用" << endl;
    cout << "5. 患者出院(顯示最終帳單)" << endl;
    cout << "6. 離開系統" << endl;
    cout << "========================================" << endl;
    cout << "請選擇操作 (1-6): ";
}

// 等待使用者按 Enter，讓費用資訊可以多停留一下
void pauseForUser()
{
    cout << "按 Enter 鍵返回主選單...";
    string pause;
    getline(cin, pause);
}

int main()
{
    // 初始化各個物件
    PatientAccount patient;
    Surgery surgery;
    Pharmacy pharmacy;
    string patientName, patientId;
    int choice;
    bool checkingOut = false;

    // ========== 第一步：入院登記 ==========
    cout << "========== 患者入院登記 ==========" << endl;
    cout << "請輸入患者姓名: ";
    getline(cin, patientName);
    cout << "請輸入患者ID: ";
    getline(cin, patientId);

    // 設置患者基本信息
    patient.setPatientName(patientName);
    patient.setPatientId(patientId);

    cout << endl
         << "患者已登記。" << endl;
    cout << "醫院每日費率已設置為: $" << fixed << setprecision(2) << patient.getDailyRate() << endl;

    // ========== 第二步：主菜單循環 ==========
    while (!checkingOut)
    {
        displayMainMenu();
        cin >> choice;
        cin.ignore();

        int inputValue = 0; // 用於接收手術/藥物選擇或住院天數
        switch (choice)
        {
        case 1: // 添加手術費用
        {
            surgery.displaySurgeryMenu();
            cout << "請選擇手術 (1-5): ";
            cin >> inputValue;
            cin.ignore();

            if (inputValue >= 1 && inputValue <= 5)
                surgery.applySurgery(patient, inputValue);
            else
                cout << "無效的選擇。請重試。" << endl;
            break;
        }

        case 2: // 添加藥物費用
        {
            pharmacy.displayPharmacyMenu();
            cout << "請選擇藥物 (1-5): ";
            cin >> inputValue;
            cin.ignore();

            if (inputValue >= 1 && inputValue <= 5)
                pharmacy.applyMedication(patient, inputValue);
            else
                cout << "無效的選擇。請重試。" << endl;
            break;
        }

        case 3: // 設置住院天數
        {
            cout << "請輸入住院天數: ";
            cin >> inputValue;
            cin.ignore();

            if (inputValue > 0)
            {
                patient.setDaysInHospital(inputValue);
                cout << "住院天數已設置為: " << inputValue << " 天" << endl;
            }
            else
                cout << "請輸入有效的天數。" << endl;
            break;
        }

        case 4: // 查看目前費用（實時查看，不包括住院費）
        {
            cout << endl
                 << "========== 目前費用統計 ==========" << endl;
            cout << "患者姓名: " << patient.getPatientName() << endl;
            cout << "患者ID:   " << patient.getPatientId() << endl;
            cout << "住院天數: " << patient.getDaysInHospital() << " 天" << endl;

            // 計算當前的各部分費用
            double hospitalCharge = patient.getDaysInHospital() * patient.getDailyRate();
            double otherCharges = patient.getCharges() - hospitalCharge;

            cout << "住院費:   $" << fixed << setprecision(2) << hospitalCharge << endl;
            cout << "其他費用: $" << fixed << setprecision(2) << otherCharges << endl;
            cout << "目前總費用: $" << fixed << setprecision(2) << patient.getCharges() << endl;
            cout << "==================================" << endl
                 << endl;
            pauseForUser();
            break;
        }

        case 5: // 患者出院：計算住院費並裝示最終帳單
        {
            patient.calculateHospitalCharges();
            patient.displayBill();
            pauseForUser();
            checkingOut = true;
            cout << "患者已安全出院。謝謝您使用本系統！" << endl;
            break;
        }

        case 6: // 離開系統（確認後退出）
        {
            cout << endl
                 << "確定要離開系統嗎？未保存的數據將丟失。" << endl;
            cout << "輸入 Y 確認，其他鍵返回: ";
            string confirm;
            getline(cin, confirm);

            if (confirm == "Y" || confirm == "y")
            {
                cout << "程序已退出。" << endl;
                checkingOut = true;
            }
            break;
        }

        default:
            cout << "無效的選擇。請輸入 1-6。" << endl;
        }
    }

    return 0;
}