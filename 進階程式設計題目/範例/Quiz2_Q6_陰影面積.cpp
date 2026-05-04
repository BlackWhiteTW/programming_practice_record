#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    const double PI = 3.14;

    for (int i = 0; i < k; i++)
    {
        double a;
        cin >> a;

        // 根據題目描述：AOB為1/4圓，以OA、OB為直徑各畫半圓
        // 陰影面積 = (PI * a * a) / 22
        double area = (PI * a * a) / 22.0;

        // 四捨五入到小數點第2位
        area = round(area * 100) / 100.0;

        cout << fixed << setprecision(2) << area << endl;
    }

    return 0;
}
