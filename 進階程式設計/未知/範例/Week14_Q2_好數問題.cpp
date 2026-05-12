#include <bits/stdc++.h>
using namespace std;

static bool isGood(long long n)
{
    if (n < 1000 || n > 9999)
        return false;
    string s = to_string(n);
    array<int, 10> cnt{};
    for (char c : s)
        cnt[c - '0']++;
    sort(cnt.begin(), cnt.end(), greater<int>());
    return cnt[0] == 2 && cnt[1] == 1 && cnt[2] == 1;
}

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        unsigned long long p;
        cin >> p;
        if (p < 1000 || p > 9999)
            cout << "Failure Input" << '\n';
        else
            cout << (isGood((long long)p) ? "Good Number" : "Wrong Number") << '\n';
    }
    return 0;
}