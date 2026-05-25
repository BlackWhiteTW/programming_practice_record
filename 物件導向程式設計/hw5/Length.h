#pragma once

#include <iostream>

using namespace std;

// 表示長度：以公分 (cm) 與毫米 (mm, 0~9) 為單位
class Length
{
private:
    int centimeters;
    int millimeters;
    void normalize();

public:
    // 建構子
    Length();
    Length(int cm, int mm);
    // 由使用者輸入長度（互動式）
    void input();
    // 顯示長度，例如: "12 cm 3 mm"
    void display() const;
    // 存取器
    int getCentimeters() const
    {
        return centimeters;
    }
    int getMillimeters() const
    {
        return millimeters;
    }
    // 回傳總毫米數（便於計算）
    long long totalMillimeters() const;
    // 由總毫米數建立 Length 物件
    static Length fromTotalMillimeters(long long mm);
    // 比較與運算子
    bool operator==(const Length &other) const;
    Length operator+(const Length &other) const;
    // 長度相乘，回傳面積（單位：平方公分）
    double operator*(const Length &other) const;
};