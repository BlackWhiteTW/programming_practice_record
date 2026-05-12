#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    if (!(cin >> k))
        return 0;
    const double PI = acos(-1.0);

    for (int i = 0; i < k; i++)
    {
        double a;
        cin >> a;
        double area = (PI * a * a) / 22.0;
        area = round(area * 100.0) / 100.0;
        cout << fixed << setprecision(2) << area << '\n';
    }

    return 0;
}
