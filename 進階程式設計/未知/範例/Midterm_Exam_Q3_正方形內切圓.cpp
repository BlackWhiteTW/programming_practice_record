#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        double L, W;
        cin >> L >> W;

        // 根據範例推導的公式
        // r = sqrt((L * W)^2 + (L + W)^2)
        double lw = L * W;
        double lw_sum = L + W;
        double r = sqrt(lw * lw + lw_sum * lw_sum);

        // 四捨五入到小數點第2位
        r = round(r * 100) / 100.0;

        cout << fixed << setprecision(2) << r << endl;
    }

    return 0;
}
