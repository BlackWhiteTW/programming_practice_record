#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    int input[4], n, ans = 0;
    for (int i = 0; i < 4; i++)
        cin >> input[i];
    cin >> n;
    for (int i = 1; i < 16; i++)
    {
        int count = 0, temp = 1;
        for (int j = 0; j < 4; j++)
        {
            if ((i >> j) & 1)
            {
                count++;
                temp = lcm(temp, input[j]);
            }
        }
        if (count % 2)
            ans += n / temp;
        else
            ans -= n / temp;
    }
    cout << ans << endl;
    return 0;
}