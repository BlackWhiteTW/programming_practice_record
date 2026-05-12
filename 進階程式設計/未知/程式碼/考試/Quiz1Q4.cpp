#include <bits/stdc++.h>

using namespace std;

int main()
{
    while (1)
    {
        string s;
        cin >> s;
        if (s == "-1")
            break;
        char ch = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1')
                ch += (1 << i);
        cout << ch;
    }
}