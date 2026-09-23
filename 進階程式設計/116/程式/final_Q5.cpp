#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (1)
    {
        int p, d;
        cin >> p;
        if (p == -1)
            return 0;
        cin >> d;
        double ans = (p * 2 * d + d * d) * 3.14;
        ans = abs(round(ans * 10) / 10.0);
        cout << fixed << setprecision(1) << ans << endl;
    }
}