#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , all = 0 , ans = 0 , tmp = 0;
    cin >> n;
    int a[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
        all += a[i];
    }
    sort( a , a+n );
    while ( tmp <= all - tmp)
    {
        tmp += a[--n];
        ans++;
    }
    cout << ans << endl;

    return 0;
}