#include <bits/stdc++.h>
using namespace std;

// 反轉二進制字符串
string reverseBinary(string binary)
{
    reverse(binary.begin(), binary.end());
    return binary;
}

// 將二進制轉換為十進制
int binaryToDecimal(string binary)
{
    int result = 0;
    for (int i = 0; i < binary.length(); i++)
    {
        result = result * 2 + (binary[i] - '0');
    }
    return result;
}

int main()
{
    string binary;

    while (cin >> binary && binary != "-1")
    {
        // 反轉二進制（因為是LSB First）
        string reversed = reverseBinary(binary);

        // 轉換為十進制
        int decimal = binaryToDecimal(reversed);

        // 轉換為字符
        char ch = (char)decimal;
        cout << ch;
    }
    cout << endl;

    return 0;
}
