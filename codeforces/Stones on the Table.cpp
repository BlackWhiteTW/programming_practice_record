#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a , ans=0;
    cin >> a;
    vector<char> str;
    for ( int i = 0 ; i < a ; i++ )
    {
        char c;
        cin >> c;
        str.push_back(c);
    }
    for (int i = 0; i < str.size() - 1; i++)
    {
        if (str[i] == str[i + 1])
        {
            str.erase(str.begin() + i);
            i--;
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}