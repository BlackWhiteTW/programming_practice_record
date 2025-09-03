#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0;
    string str;
    cin >> str;
    sort( str.begin() , str.end() );
    for ( int i = 0 ; i < str.size() - 1 ; i++ )
    {
        if( str[i] != str[i+1] )
            ans++;
    }
    
    if ( ans % 2 == 0 )
        cout << "IGNORE HIM!";
    else
        cout << "CHAT WITH HER!";
    
    return 0;
}