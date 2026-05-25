#include "Journal.h"
#include "Input.h"

#include <iostream>

using namespace std;

Journal::Journal()
    : month(0), ISSN(""), impactFactor(0.0), annualSubscription(0.0) {}

Journal::~Journal() {}

void Journal::input()
{
    Publication::input();
    month = input::input_i("請輸入月份（1-12）：", 1, 12);
    ISSN = input::input_str("請輸入 ISSN：");
    impactFactor = input::input_d("請輸入影響因子：");
    annualSubscription = input::input_d("請輸入年度訂閱費：");
}

void Journal::display() const
{
    cout << "=== 期刊 ===" << endl;
    Publication::display();
    cout << "月份：" << month << '\n';
    cout << "ISSN：" << ISSN << '\n';
    cout << "影響因子：" << impactFactor << '\n';
    cout << "年度訂閱費：" << annualSubscription << '\n';
}
