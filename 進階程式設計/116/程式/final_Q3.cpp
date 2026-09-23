#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (1)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if (x < 1 || y < 2 || z < 1)
            return 0;
        int ans = z / x, temp = z / x;
        while (temp >= y)
        {
            ans += temp / y;
            temp = temp / y + temp % y;
        }
        cout << ans << " " << z % x << " " << temp << endl;
    }
}