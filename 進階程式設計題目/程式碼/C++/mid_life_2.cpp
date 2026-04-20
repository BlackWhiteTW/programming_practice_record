#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        bool check = 1;
        int m;
        cin >> m;
        bool bit_m[8] = {0};
        for (int i = 0; i < 8; i++)
        {
            if (m & (1 << i))
                bit_m[i] = 1;
        }
        for (int i = 0; i < 4; i++)
        {
            if ((bit_m[i]) != (bit_m[7 - i]))
            {
                check = 0;
                break;
            }
        }
        if (check)
            cout << m << endl;
    }
    return 0;
}