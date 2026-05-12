#include <bits/stdc++.h>
using namespace std;

int reverseBits(int n)
{
    int result = 0;
    for (int i = 0; i < 8; i++)
    {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}

int main()
{
    int k;
    if (!(cin >> k))
        return 0;

    uint8_t checksum = 0;

    // 使用多項式 0x31 (00110001)，以 MSB-first 位元運算計算 CRC-8
    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;
        uint8_t b = static_cast<uint8_t>(num);

        checksum ^= b;
        for (int bit = 0; bit < 8; ++bit)
        {
            if (checksum & 0x80)
                checksum = static_cast<uint8_t>((checksum << 1) ^ 0x31);
            else
                checksum = static_cast<uint8_t>(checksum << 1);
        }
    }

    int result = reverseBits(checksum);
    cout << result << endl;

    return 0;
}
