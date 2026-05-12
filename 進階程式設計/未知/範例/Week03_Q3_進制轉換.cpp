#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        string hex_str;
        cin >> hex_str;

        // Parse hexadecimal string (remove "0x" prefix)
        unsigned int num = 0;
        if (hex_str.substr(0, 2) == "0x" || hex_str.substr(0, 2) == "0X")
        {
            hex_str = hex_str.substr(2);
        }

        // Convert hex string to integer
        num = stoul(hex_str, nullptr, 16);

        // Convert to 32-bit binary and format with spaces every 4 bits
        string binary = "";
        for (int j = 31; j >= 0; j--)
        {
            binary += ((num >> j) & 1) ? '1' : '0';
        }

        // Add spaces every 4 bits
        string result = "";
        for (int j = 0; j < 32; j++)
        {
            if (j > 0 && j % 4 == 0)
            {
                result += " ";
            }
            result += binary[j];
        }

        cout << result << "\n";
    }

    return 0;
}
