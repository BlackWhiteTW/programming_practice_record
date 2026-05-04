#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int x, y;
        char comma;
        cin >> x >> comma >> y; // Read x,y format

        if (x == 0 && y == 0)
        {
            cout << 0 << "\n";
        }
        else if (x == 0)
        {
            cout << 6 << "\n";
        }
        else if (y == 0)
        {
            cout << 5 << "\n";
        }
        else if (x > 0 && y > 0)
        {
            cout << 1 << "\n";
        }
        else if (x < 0 && y > 0)
        {
            cout << 2 << "\n";
        }
        else if (x < 0 && y < 0)
        {
            cout << 3 << "\n";
        }
        else if (x > 0 && y < 0)
        {
            cout << 4 << "\n";
        }
    }

    return 0;
}
