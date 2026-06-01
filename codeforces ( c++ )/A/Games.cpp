#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t, ans = 0;
    cin >> t;
    vector<pair<int, int>> list;
    for (int i = 0; i < t; i++)
    {
        int a, b;
        cin >> a >> b;
        list.push_back({a, b});
    }
    for (int i = 0; i < t; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (list[i].first == list[j].second)
                ans++;
        }
    }
    cout << ans << endl;
    return 0;
}