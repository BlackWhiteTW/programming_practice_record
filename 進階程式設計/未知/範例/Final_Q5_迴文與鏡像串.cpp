#include <bits/stdc++.h>
using namespace std;

char getMirror(char c)
{
    map<char, char> mirror = {
        {'A', 'A'}, {'H', 'H'}, {'I', 'I'}, {'M', 'M'}, {'O', 'O'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'}, {'B', 0}, {'C', 0}, {'D', 0}, {'E', 0}, {'F', 0}, {'G', 0}, {'J', 0}, {'K', 0}, {'L', 0}, {'N', 0}, {'P', 0}, {'Q', 0}, {'R', 0}, {'S', 0}, {'Z', 0}, {'a', 0}, {'b', 'd'}, {'c', 0}, {'d', 'b'}, {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l', 0}, {'m', 'm'}, {'n', 0}, {'o', 'o'}, {'p', 'q'}, {'q', 'p'}, {'r', 0}, {'s', 0}, {'t', 0}, {'u', 'u'}, {'v', 'v'}, {'w', 'w'}, {'x', 'x'}, {'y', 0}, {'z', 0}, {'0', '0'}, {'1', '1'}, {'2', '2'}, {'3', '3'}, {'4', 0}, {'5', '5'}, {'6', '9'}, {'7', 0}, {'8', '8'}, {'9', '6'}};
    return mirror.count(c) && mirror[c] ? mirror[c] : (char)0;
}

int main()
{
    int L;
    cin >> L;

    for (int i = 0; i < L; i++)
    {
        string s;
        cin >> s;

        // 檢查是否為迴文
        string reversed = s;
        reverse(reversed.begin(), reversed.end());
        bool isPalindrome = (s == reversed);

        // 檢查是否為鏡像串
        bool isMirrored = true;
        for (int j = 0; j < s.length(); j++)
        {
            char mirror = getMirror(s[j]);
            if (mirror == 0)
            {
                isMirrored = false;
                break;
            }
            if (mirror != s[s.length() - 1 - j])
            {
                isMirrored = false;
                break;
            }
        }

        cout << s << " -- is ";
        if (isPalindrome && isMirrored)
        {
            cout << "a mirrored palindrome." << endl;
        }
        else if (isPalindrome)
        {
            cout << "a regular palindrome." << endl;
        }
        else if (isMirrored)
        {
            cout << "a mirrored string." << endl;
        }
        else
        {
            cout << "only a string." << endl;
        }
    }

    return 0;
}
