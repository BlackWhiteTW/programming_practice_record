#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    const double pi = 3.141;
    for (int i = 0; i < k; ++i)
    {
        double a;
        cin >> a;
        double area = a * a - pi * a * a / 4.0;
        cout << fixed << setprecision(2) << area + 1e-9 << '\n';
    }
    return 0;
}