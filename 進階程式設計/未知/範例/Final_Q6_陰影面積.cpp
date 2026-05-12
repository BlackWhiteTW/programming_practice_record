#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        double L;
        cin >> L;

        // 陰影面積 ∆AED = L^2 / 2
        double area = L * L / 2.0;

        // 四捨五入到小數點第2位
        area = round(area * 100) / 100.0;

        cout << fixed << setprecision(2) << area << endl;
    }

    return 0;
}
