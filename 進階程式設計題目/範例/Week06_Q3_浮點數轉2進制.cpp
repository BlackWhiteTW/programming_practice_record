#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        float value;
        cin >> value;
        uint32_t bits;
        memcpy(&bits, &value, sizeof(bits));
        for (int bit = 31; bit >= 0; --bit)
        {
            cout << ((bits >> bit) & 1);
            if (bit % 8 == 0 && bit != 0)
                cout << ' ';
        }
        cout << '\n';
    }
    return 0;
}