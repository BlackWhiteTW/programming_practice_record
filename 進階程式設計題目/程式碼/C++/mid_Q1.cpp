#include <bits/stdc++.h>

using namespace std;

int main()
{
    for (int i = 0; i < 5; i++)
    {
        int a, b;
        cin >> a >> b;
        if (b < a * 2 || b % 2 || b > a * 4)
            cout << "no solution" << endl;
        else
        {
            cout << (a - (b - 2 * a) / 2) << " " << ((b - 2 * a) / 2) << endl;
        }
    }
}

// a = 252 b = 872
// 2a = 504
// b - 2a = 368
// 368 / 2 = 184
// 252 - 184 = 68