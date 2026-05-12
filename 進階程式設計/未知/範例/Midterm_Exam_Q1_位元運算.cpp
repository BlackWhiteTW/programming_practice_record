#include <bits/stdc++.h>
using namespace std;

int swapBits(int v)
{
    int result = 0;
    for (int i = 0; i < 8; i++)
    {
        if (v & (1 << i))
        {
            result |= (1 << (7 - i));
        }
    }
    return result;
}

int main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int v1, v2;
        char m;
        cin >> v1 >> v2 >> m;

        int result;

        if (m == 'a')
        {
            // 模式 a：v1 的奇數位元與 v2 的偶數位元進行 AND 運算
            int v1_odd = 0, v2_even = 0;
            for (int j = 0; j < 16; j += 2)
            {
                if (v1 & (1 << j))
                {
                    v1_odd |= (1 << (j / 2));
                }
            }
            for (int j = 1; j < 16; j += 2)
            {
                if (v2 & (1 << j))
                {
                    v2_even |= (1 << (j / 2));
                }
            }
            result = v1_odd & v2_even;
        }
        else
        {
            // 模式 b：交換位元後進行 OR 運算
            int v1_swapped = swapBits(v1 & 0xFF);
            int v2_swapped = swapBits(v2 & 0xFF);

            int v1_high = (v1_swapped >> 4) & 0x0F;
            int v2_low = v2_swapped & 0x0F;

            result = (v1_high << 4) | v2_low;
        }

        cout << result << endl;
    }

    return 0;
}
