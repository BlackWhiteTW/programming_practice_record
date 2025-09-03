#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , k , ans = 0;
    cin >> n >> k ;
    vector<int> v;
    for ( int i = 0 ; i < n ; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    for ( int i = 0 ; i < n ; i++ )
        if ( v[i] > 0 && v[i] >= v[k-1])
            ans++;

    cout << ans << endl;

    return 0;
}