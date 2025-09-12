#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n , k , ans = 0 ;
    cin >> n >> k ;
    if ( k <= ( n + 1 ) / 2)
        ans = -1 + k * 2 ;
    else
        ans = ( k - ( n + 1 ) / 2) * 2 ;
    cout << ans << endl;

    return 0 ;
}