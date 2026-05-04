#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 英文字母對應表
    map<char, int> charMap = {
        {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}, {'G', 16}, {'H', 17}, {'I', 34}, {'J', 18}, {'K', 19}, {'L', 20}, {'M', 21}, {'N', 22}, {'O', 35}, {'P', 23}, {'Q', 24}, {'R', 25}, {'S', 26}, {'T', 27}, {'U', 28}, {'V', 29}, {'W', 32}, {'X', 30}, {'Y', 31}, {'Z', 33}};

    string id;
    while (cin >> id && id != "-1")
    {
        // 規則1 & 2：將英文字母轉換並計算 N1
        int num = charMap[id[0]];
        int tens = num / 10;
        int ones = num % 10;
        int N1 = (tens + ones * 9) % 10;

        // 規則3：計算前8碼的加權和
        int N2 = 0;
        for (int i = 1; i <= 8; i++)
        {
            N2 += (id[i] - '0') * (9 - i);
        }

        // 規則4：計算 N3
        int N3 = (N1 + N2) % 10;

        // 規則5：驗證最後一碼
        int checkDigit = (10 - N3) % 10;
        int lastDigit = id[9] - '0';

        if (checkDigit == lastDigit)
        {
            cout << "Real" << endl;
        }
        else
        {
            cout << "Fake" << endl;
        }
    }

    return 0;
}
