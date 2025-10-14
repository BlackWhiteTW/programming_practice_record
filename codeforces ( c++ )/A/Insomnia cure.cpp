#include <bits/stdc++.h>

using namespace std;

int main()
{
    int in[5] , ans = 0;
    for ( int i = 1 ; i <= 4 ; i++ )
        cin >> in[i];
    for ( int i = 1 ; i < 4 ; i++ )
        if ( in[i] == 1 )
            ans = in[4] ;

    if ( ans == in[4] )
        cout << ans << endl;
    else
    {
        
    }

}