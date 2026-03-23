#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        char ch;
        cin >> x >> ch >> y;
        if (x == 0 && y == 0)
            cout << "0" << endl;
        else if (x == 0)
            cout << "6" << endl;
        else if (y == 0)
            cout << "5" << endl;
        else if (x > 0 && y > 0)
            cout << "1" << endl;
        else if (x < 0 && y > 0)
            cout << "2" << endl;
        else if (x < 0 && y < 0)
            cout << "3" << endl;
        else
            cout << "4" << endl;
    }
}