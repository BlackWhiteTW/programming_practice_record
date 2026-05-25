#include "Magazine.h"
#include "Input.h"

#include <iostream>

using namespace std;

Magazine::Magazine()
    : month(0), editor(""), annualSubscription(0.0) {}

Magazine::~Magazine() {}

void Magazine::input()
{
    Publication::input();
    month = input::input_i("請輸入月份（1-12）：", 1, 12);
    editor = input::input_str("請輸入編輯：");
    annualSubscription = input::input_d("請輸入年度訂閱費：");
}

void Magazine::display() const
{
    cout << "=== 雜誌 ===" << endl;
    Publication::display();
    cout << "月份：" << month << '\n';
    cout << "編輯：" << editor << '\n';
    cout << "年度訂閱費：" << annualSubscription << '\n';
}
