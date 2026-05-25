#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = 0;
    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (b > 100)
        {
            v.push_back(a);
            ans += (b - 100) * 5;
        }
    }

    if (v.empty())
        cout << 0 << endl;
    else
    {
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << (i == v.size() - 1 ? "" : " ");
        cout << endl;
        cout << ans << endl;
    }
    return 0;
}