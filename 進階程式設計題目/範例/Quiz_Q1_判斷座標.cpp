#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        char comma;
        cin >> x >> comma >> y;

        if (x == 0 && y == 0)
        {
            cout << 0 << endl; // 原點
        }
        else if (x > 0 && y > 0)
        {
            cout << 1 << endl; // 第1象限
        }
        else if (x < 0 && y > 0)
        {
            cout << 2 << endl; // 第2象限
        }
        else if (x < 0 && y < 0)
        {
            cout << 3 << endl; // 第3象限
        }
        else if (x > 0 && y < 0)
        {
            cout << 4 << endl; // 第4象限
        }
        else if (x != 0 && y == 0)
        {
            cout << 5 << endl; // x軸
        }
        else if (x == 0 && y != 0)
        {
            cout << 6 << endl; // y軸
        }
    }

    return 0;
}
