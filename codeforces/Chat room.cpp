#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    char t[] = {'h', 'e', 'l', 'l', 'o'};
    int j = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == t[j])
        {
            j++;
        }
        if (j == 5)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}