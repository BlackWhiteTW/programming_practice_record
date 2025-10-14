#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[3] , ans = 1 , t = -1 , t1 , t2 , tt = 0;
    for ( int i = 0; i < 3; i++)
        cin >> a[i];
    ans = a[0];
    for ( int i = 0 ; i < 3 ; i++)
    {
        if ( a[i] == 1 )
        {
            tt++;
            t = i;
        }
    }
    if ( tt == 0 )
        ans *= a[1] * a[2];
    else if ( tt == 3 )
        ans = 3;
    else if ( tt == 2 )
        for ( int i = 0 ; i < 3 ; i++)
            if ( a[i] != 1 && i != 1)
                ans = a[i] * 2;
    if ( ans == a[0] )
                ans = a[0] + a[1] + a[2];

    if ( tt == 1 )
    {
        if ( t == 0 )
            ans = a[2] * ( a[1] + 1 );
        else if ( t == 1 )
        {
            t1 = a[0];
            t2 = a[2];
            if ( t1 > t2 )
                ans = t1 * ( t2 + 1 );
            else
                ans = t2 * ( t1 + 1 );
        }
        else
            ans = a[0] * ( a[1] + 1 );
    }
    cout << ans << endl;
}