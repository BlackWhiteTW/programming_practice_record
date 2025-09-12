#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str1 , str2;
    cin >> str1 >> str2;
    
    if ( str1.size() != str2.size() )
    {
        cout << "NO" << endl;
        return 0;
    }

    for ( int i = 0 ; i < str1.size() ; i++ )
    {
        if ( str1[i] != str2[str2.size() - 1 - i] )
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

    return 0;
}