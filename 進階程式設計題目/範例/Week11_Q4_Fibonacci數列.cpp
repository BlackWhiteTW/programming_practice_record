#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> fib = {0, 1};
    while (fib.back() < 1000000000LL)
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);

    long long m, n;
    while (cin >> m && m != -1)
    {
        cin >> n;
        vector<long long> out;
        for (long long f : fib)
            if (f >= m && f <= n)
                out.push_back(f);
        if (out.empty())
            cout << "null";
        else
        {
            for (size_t i = 0; i < out.size(); ++i)
            {
                if (i)
                    cout << ' ';
                cout << out[i];
            }
        }
        cout << '\n';
    }
    return 0;
}