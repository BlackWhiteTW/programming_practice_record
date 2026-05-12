#include <bits/stdc++.h>
using namespace std;

static bool isLeap(int y)
{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

int main()
{
    int m, n;
    cin >> m >> n;
    int cnt = 0;
    for (int y = m; y <= n; ++y)
        if (isLeap(y))
            ++cnt;
    cout << cnt << '\n';
    return 0;
}