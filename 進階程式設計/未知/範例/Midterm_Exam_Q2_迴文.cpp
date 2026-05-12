#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int num)
{
    // 將整數轉換為 8-bit 二進制表示
    unsigned char byte = (unsigned char)num;

    string binary = "";
    for (int i = 0; i < 8; i++)
    {
        binary += ((byte >> i) & 1) ? '1' : '0';
    }

    // 檢查是否為迴文
    string reversed = binary;
    reverse(reversed.begin(), reversed.end());

    return binary == reversed;
}

int main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;

        if (isPalindrome(num))
        {
            cout << num << endl;
        }
    }

    return 0;
}
