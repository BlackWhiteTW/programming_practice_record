#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, a = 0;
        cin >> n;
        vector<pair<int, int>> list;
        while (n > 0)
        {
            if (n % 10 != 0)
                list.push_back({n % 10, a});
            n /= 10;
            a++;
        }
        cout << list.size() << endl;
        for (int i = list.size() - 1; i >= 0; i--)
        {
            if (list[i].first != 0)
            {
                cout << list[i].first * pow(10, list[i].second) << " ";
            }
        }
        cout << endl;
    }
}