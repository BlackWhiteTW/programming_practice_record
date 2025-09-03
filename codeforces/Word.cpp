#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    int up = 0 , low = 0;
    for ( int i = 0 ; i < str.size() ; i++ )
    {
        if ( isupper(str[i]) )
            up++;
        else
            low++;
    }
    if ( up > low)
        transform( str.begin() , str.end() , str.begin() , ::toupper );
    else
        transform( str.begin() , str.end() , str.begin() , ::tolower );

    cout << str << endl;

    return 0;
}