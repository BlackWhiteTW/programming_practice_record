#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    while (1)
    {
        int n;
        cin >> n;
        if (n == -1)
            break;
        v.push_back(n);
    }
    sort(v.begin(), v.end());
    float m, M;
    if (v.size() % 2 == 0)
        M = (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2.0;
    else
        M = v[v.size() / 2];
    for (int i = 0; i < v.size(); i++)
        m += v[i];
    cout.precision(1);
    cout << fixed << m / v.size() << " " << M << endl;
}