#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , h , ans = 0;
    cin >> n >> h;
    for ( int i = 0 ; i < n ; i++ )
    {
        int a;
        cin >> a;
        if ( a > h )
            ans++;
        ans++;
    }
    
    cout << ans << endl;

    return 0;
}