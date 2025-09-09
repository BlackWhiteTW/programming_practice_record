#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n] , b[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        cin>>a[i]>>b[i];
    }
    for ( int i = 0 ; i < n ; i++ )
    {
        for ( int j = 0 ; j < a[i] ; j++ )
            b[i] *= 2;
    }
    for ( int i = 0 ; i < n ; i++ )
        cout<<b[i]<<endl;

    return 0;
}

