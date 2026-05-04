#include <bits/stdc++.h>
using namespace std;

static bool isArmstrong(long long n)
{
    string s = to_string(n);
    int len = (int)s.size();
    long long sum = 0;
    for (char c : s)
    {
        long long d = c - '0';
        long long p = 1;
        for (int i = 0; i < len; ++i)
            p *= d;
        sum += p;
    }
    return sum == n;
}

int main()
{
    long long n;
    while (cin >> n && n != -1)
    {
        cout << (isArmstrong(n) ? "Yes" : "No") << '\n';
    }
    return 0;
}