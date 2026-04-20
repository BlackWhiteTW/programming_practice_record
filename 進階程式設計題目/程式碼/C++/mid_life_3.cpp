#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        double L, W, R = 0;
        cin >> L >> W;
        R = L + W + sqrt(2 * L * W);
        cout.precision(2);
        cout << fixed << R << endl;
    }
}

// r^2 = (r - L)^2 + (r - W)^2
// r^2 = r^2 - 2rL + L^2 + r^2 - 2rW + W^2
// 0 = r^2 - 2rL + L^2 - 2rW + W^2
// 0 = r^2 - 2r(L + W) + L^2 + W^2
// r = (2(L + W) +- sqrt(4(L + W)^2 - 4(L^2 + W^2))) / 2
// r = L + W +- sqrt(2LW) (r > 0, so r = L + W + sqrt(2LW))