#include "Length.h"

#include <limits>

using namespace std;

Length::Length() : centimeters(0), millimeters(0) {}
Length::Length(int cm, int mm) : centimeters(cm), millimeters(mm) { normalize(); }

// normalize: 進借位控制
void Length::normalize()
{
    if (millimeters >= 10 || millimeters <= -10)
    {
        int carry = millimeters / 10;
        centimeters += carry;
        millimeters -= carry * 10;
    }
    if (millimeters < 0)
    {
        int borrow = ((-millimeters) + 9) / 10;
        centimeters -= borrow;
        millimeters += borrow * 10;
    }
}

void Length::input()
{
    int cm;
    while (1)
    {
        cout << "輸入公分 (整數)：";
        if (!(cin >> cm))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "無效的整數，請重試。\n";
        }
        else if (cm < 0)
            cout << "公分需為非負整數，請重試。\n";
        else
            break;
    }
    int mm;
    while (1)
    {
        cout << "輸入毫米 (0~9)：";
        if (!(cin >> mm))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "無效的整數，請重試。\n";
        }
        else if (mm < 0 || mm >= 10)
            cout << "毫米需介於 0~9，請重試。\n";
        else
            break;
    }
    centimeters = cm;
    millimeters = mm;
    // 清掉本行其他輸入
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    normalize();
}

// 顯示為 "X cm Y mm"
void Length::display() const
{
    cout << centimeters << " cm " << millimeters << " mm";
}

// 回傳總毫米數（便於加總比較）
long long Length::totalMillimeters() const
{
    return static_cast<long long>(centimeters) * 10 + millimeters;
}

// 由總毫米數建立 Length（支援負值）
Length Length::fromTotalMillimeters(long long mm)
{
    int cm = static_cast<int>(mm / 10);
    int rem = static_cast<int>(mm % 10);
    if (rem < 0)
    {
        rem += 10;
        cm -= 1;
    }
    return Length(cm, rem);
}

// 比較兩個長度是否相等
bool Length::operator==(const Length &other) const
{
    return totalMillimeters() == other.totalMillimeters();
}

// 加法：回傳新的 Length
Length Length::operator+(const Length &other) const
{
    long long sum = totalMillimeters() + other.totalMillimeters();
    return fromTotalMillimeters(sum);
}

// 乘法：回傳面積（單位：平方公分）
double Length::operator*(const Length &other) const
{
    double a_cm = static_cast<double>(totalMillimeters()) / 10.0;
    double b_cm = static_cast<double>(other.totalMillimeters()) / 10.0;
    return a_cm * b_cm; // cm^2
}
