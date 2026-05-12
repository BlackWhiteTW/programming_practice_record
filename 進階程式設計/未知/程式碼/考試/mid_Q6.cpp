#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m;
    cin >> m;

    while (m--)
    {
        double r, d;
        cin >> r;
        d = r * sqrt(2);
        cout.precision(2);
        cout << fixed << round(r * r * 21.5 ) / 100<< endl;
    }

    return 0;
}
