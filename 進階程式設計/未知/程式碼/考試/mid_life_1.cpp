#include <bits/stdc++.h>

using namespace std;

int main()
{
    uint16_t a, b, ans = 0;
    int n;
    cin >> n;
    char c;
    while (n--)
    {
        ans = 0;
        cin >> a >> b >> c;
        bool bit_a[16] = {0}, bit_b[16] = {0};
        cout << a << " " << b << " " << c << " = ";
        for (int i = 0; i < 16; i++)
        {
            bit_a[i] = a & (1 << i);
            bit_b[i] = b & (1 << i);
        }
        if (c == 'a')
        {
            for (int i = 0; i < 8; i++)
            {
                ans += (bit_a[i * 2 + 1] & bit_b[i * 2]) << i;
            }
        }
        else
        {
            for (int i = 0; i < 4; i++)
            {
                swap(bit_a[15 - i], bit_a[8 + i]);
                swap(bit_b[7 - i], bit_b[i]);
            }
            for (int i = 0; i < 8; i++)
            {
                ans += (bit_a[i + 8] | bit_b[i]) << i;
            }
        }
        cout << ans << endl;
    }
}