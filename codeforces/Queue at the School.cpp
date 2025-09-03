#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , t;
    string s;
    cin >> t >> n >> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (s[j] == 'B' && s[j + 1] == 'G')
            {
                swap(s[j], s[j + 1]);
                j++;
            }
        }
    }
    cout << s << endl;
}