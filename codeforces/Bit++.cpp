#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t , ans = 0;
    cin >> t;
    for ( int i = 0 ; i < t ; i++ )
    {
        string str;
        cin >> str;
        if ( str[1] == '+' )
            ans++;
        else
            ans--;
    }

    cout << ans << endl;

    return 0;
}