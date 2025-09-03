#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int tmp = 1;
    for ( int i = 0 ; i < str.size() ; i++ )
    {
        if ( str[i] == str[i+1] )
            tmp++;
        else
            tmp = 1;
        
        if ( tmp >= 7)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}