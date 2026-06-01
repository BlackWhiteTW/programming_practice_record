#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> a(7, 0);
    for (int i = 0; i < 7; i++)
        cin >> a[i];
    int n, ans = 0;
    cin >> n;
    vector<int> b(6, 0);
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        for (int j = 0; j < 6; j++)
            cin >> b[j];
        for (int j = 0; j < 6; j++)
            for (int k = 0; k < 6; k++)
                if (b[j] == a[k])
                    t++;
        if (t == 6)
            ans += 1000000;
        else if (t == 5 && find(b.begin(), b.end(), a[6]) != b.end())
            ans += 100000;
        else if (t == 5)
            ans += 10000;
        else if (t == 4)
            ans += 1000;
        else if (t == 3)
            ans += 100;
    }
    if (ans == 0)
        cout << "null" << endl;
    else
        cout << ans << endl;
    return 0;
}