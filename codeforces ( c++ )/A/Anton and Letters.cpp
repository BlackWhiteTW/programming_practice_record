#include <bits/stdc++.h>

using namespace std;

int main()
{
    int list[26] = {0};
    string s;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
            list[s[i] - 'a'] = 1;
    }
    int count = 0;
    for (int i = 0; i < 26; i++)
    {
        count += list[i];
    }
    cout << count << "\n";
    return 0;
}