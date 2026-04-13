#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, list[26] = {0};
    cin >> n;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] >= 'a' && s[j] <= 'z')
                list[s[j] - 'a']++;
            else if (s[j] >= 'A' && s[j] <= 'Z')
                list[s[j] - 'A']++;
        }
    }
    int max = 0;
    for (int j = 0; j < 26; j++)
        if (list[j] > max)
            max = list[j];

    for (int j = max; j > 0; j--)
        for (int k = 0; k < 26; k++)
            if (list[k] == j)
                cout << (char)(k + 'A') << " " << j << endl;
}