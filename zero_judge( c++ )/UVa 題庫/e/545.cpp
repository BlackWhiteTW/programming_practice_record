#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in, b1 = 0, b2 = 0, temp;
        cin >> in;
        temp = in;
        while (temp)
        {
            if (temp % 2)
                b1++;
            temp /= 2;
        }
        temp = 1;
        while (in / temp)
        {
            int t = in / temp;
            t %= 10;
            while (t)
            {
                if (t % 2)
                    b2++;
                t /= 2;
            }
            temp *= 10;
        }
        cout << b1 << " " << b2 << endl;
    }
}