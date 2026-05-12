#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        double a, b;
        char comma;
        cin >> a >> comma >> b;
        double area = a * a / (b - a);
        cout << fixed << setprecision(2) << area << '\n';
    }
    return 0;
}