#include <bits/stdc++.h>

using namespace std;

int n;
long long ans = 0;

void dfs( int d, int l, int s, int a[4] )
{
    if ( d == 3 )
    {
        int l = n - s;
        if ( l > a[2] && l < n - 5 )
            ans++;
        return;
    }
    for ( int i = l + 1 ; s + i + (3 - d - 1) * (i + 1) < n ; i++ )
    {
        a[d] = i;
        dfs( d + 1 , i , s + i , a);
    }
}

int main()
{
    cout << "N = ";
    cin >> n;
    int a[4] = {0};
    dfs(0, 0, 0, a);
    cout << "Total is " << ans << "." << endl;

    system("pause");
    return 0;
}