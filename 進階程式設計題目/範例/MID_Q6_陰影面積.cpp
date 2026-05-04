#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    const double PI = 3.14;

    for (int i = 0; i < k; i++)
    {
        double r;
        cin >> r;

        // ∆AOB 為直角等腰三角形，O 為圓心
        // 陰影面積 = (4 - π) * r^2 / 4
        double area = (4 - PI) * r * r / 4.0;

        // 四捨五入到小數點第2位
        area = round(area * 100) / 100.0;

        cout << fixed << setprecision(2) << area << endl;
    }

    return 0;
}
