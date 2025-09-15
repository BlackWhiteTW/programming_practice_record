#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , tmp , p , q ;
    cin >> n;
    bool flag = false;
    vector <int> v ;

    cin >> p ;
    for ( int i = 0 ; i < p ; i++ )
    {
        cin >> tmp ;
        v.push_back( tmp ) ;
    }

    cin >> q ;
    for ( int i = 0 ; i < q ; i++ )
    {
        cin >> tmp ;
        v.push_back( tmp ) ;
    }

    sort ( v.begin() , v.end() ) ;

    tmp = 0 ;
    for ( int i = 0 ; i < v.size() ; i++ )
    {
        if ( v[i] == tmp + 1 )
        {
            tmp++ ;
        }
    }
    if ( tmp == n )
        cout << "I become the guy." << endl ;
    else
        cout << "Oh, my keyboard!" << endl ;
}