#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int q , ans = 0;
    cin >> q;
    for ( int i = 0 ; i < q ; i++)
    {
        int a = 0 , b = 0 , c = 0 ;
        cin >> a >> b >> c ;
        if ( a + b + c > 1 )
        {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}