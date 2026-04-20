#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (1)
    {
        string input;
        cin >> input;
        if (input == "-1")
            break;
        int list[26] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 244, 25, 26, 27, 28, 29, 32, 30, 31, 33};
        int sum = 0;
        sum += list[input[0] - 'A'] / 10 + (list[input[0] - 'A'] % 10) * 9;
        for (int i = 1; i < 9; i++)
        {
            sum += (input[i] - '0') * (9 - i);
        }
        sum += input[9] - '0';
        if (sum % 10 == 0)
            cout << "Real" << endl;
        else
            cout << "Fake" << endl;
    }
}