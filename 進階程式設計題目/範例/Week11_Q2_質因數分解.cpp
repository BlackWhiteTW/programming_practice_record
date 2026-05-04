#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        long long n;
        cin >> n;
        bool first = true;
        for (long long p = 2; p * p <= n; ++p)
        {
            while (n % p == 0)
            {
                if (!first)
                    cout << ' ';
                cout << p;
                first = false;
                n /= p;
            }
        }
        if (n > 1)
        {
            if (!first)
                cout << ' ';
            cout << n;
        }
        cout << '\n';
    }
    return 0;
}