#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, n;
    cin >> T >> n;
    vector<long long> prices(T);
    for (int i = 0; i < T; ++i)
        cin >> prices[i];

    long long sum = 0;
    queue<long long> q;
    cout << fixed << setprecision(2);
    for (int i = 0; i < T; ++i)
    {
        q.push(prices[i]);
        sum += prices[i];
        if ((int)q.size() > n)
        {
            sum -= q.front();
            q.pop();
        }
        if ((int)q.size() < n)
            cout << -1 << '\n';
        else
            cout << (sum / (double)n) << '\n';
    }
    return 0;
}