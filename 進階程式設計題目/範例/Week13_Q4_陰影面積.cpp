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
        cout << llround(a * b / 2.0) << '\n';
    }
    return 0;
}