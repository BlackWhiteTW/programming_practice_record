#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < n; i++)
    {
        if (i - 1 < 0)
            cout << (v[n - 1] + v[i + 1]) % 2 << " ";
        else if (i + 1 >= n)
            cout << (v[i - 1] + v[0]) % 2 << " ";
        else
            cout << (v[i - 1] + v[i + 1]) % 2 << " ";
    }
    cout << endl;
    return 0;
}