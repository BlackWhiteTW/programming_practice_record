#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    string str;
    cin >> str;
    for ( int i = 0 ; i < str.size() ; i += 2 )
    {
        v.push_back( str[i] - '0' );
    }
    sort( v.begin() , v.end() );
    for ( int i = 0 ; i < v.size() ; i++ )
    {
        if ( i < v.size() - 1 )
            cout << v[i] << "+";
        else
            cout << v[i];
    }
}
