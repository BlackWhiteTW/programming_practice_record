#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long m, n;
    cin >> m >> n;
    if (m > n)
    {
        cout << "Fail" << '\n';
        return 0;
    }
    long long change = n - m;
    vector<long long> coins = {2000, 1000, 500, 100, 50, 10, 5, 1};
    for (long long c : coins)
    {
        cout << change / c << '\n';
        change %= c;
    }
    return 0;
}