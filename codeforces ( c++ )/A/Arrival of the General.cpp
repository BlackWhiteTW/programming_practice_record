#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ;
    cin >> n ;
    vector <int> v(n) ;
    for ( int i = 0 ; i < n ; i++ )
        cin >> v[i] ;
    int max = v[0] , min = v[0] , pos1 = 0 , pos2 = 0 ;
    for ( int i = 1 ; i < n ; i++ )
    {
        if ( v[i] > max )
        {
            pos1 = i ;
            max = v[i] ;
        }
        if ( v[i] <= min )
        {
            pos2 = i ;
            min = v[i] ;
        }
    }
    int ans = pos1 + (n - 1 - pos2);
    if ( pos2 < pos1 )
        ans-- ;
    cout << ans << endl ;

}