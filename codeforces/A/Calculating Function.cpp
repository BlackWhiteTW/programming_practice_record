#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i , ans = 0 ;
    cin >> i ;
    if ( i % 2 == 0 )
        ans = i / 2 ;
    else
        ans = - ( ( i + 1 ) / 2 ) ;

    cout << ans << endl;

    return 0 ;
}