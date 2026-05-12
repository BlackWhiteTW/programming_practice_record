#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
    {
        int left = (i == 0 ? a[n - 1] : a[i - 1]);
        int right = (i == n - 1 ? a[0] : a[i + 1]);
        b[i] = left ^ right;
    }
    for (int i = 0; i < n; ++i)
    {
        if (i)
            cout << ' ';
        cout << b[i];
    }
    cout << '\n';
    return 0;
}