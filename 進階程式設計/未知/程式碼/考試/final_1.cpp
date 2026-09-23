#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    uint8_t checksun = 0;
    cin >> k;
    while (k--)
    {
        int input, temp = 0;
        cin >> input;
        checksun ^= static_cast<uint8_t>(input);
        for (int i = 0; i < 8; i++)
        {
            if (checksun & 0x80)
                checksun = (checksun << 1) ^ 0x31;
            else
                checksun <<= 1;
        }
    }
    int ans = 0;
    for (int i = 0; i < 8; i++)
    {
        ans += (checksun >> i & 1) << (7 - i);
    }
    cout << ans << endl;
}