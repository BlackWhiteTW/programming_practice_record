#include <bits/stdc++.h>

using namespace std;

int up(int c, int d, int time)
{
    if (c <= d)
    {
        c *= 3;
        d *= 2;
        time++;
        return up(c, d, time);
    }
    return time;
}

int main()
{
    int a , b , ans = 0;
    cin >> a >> b;
    ans = up(a, b, ans);

    cout << ans;

    return 0;
}