#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ;
    cin >> n ;
    for ( int i = 0 ; i < n ; i++ )
    {
        cout << "I ";
        if ( i % 2 == 0 )
            cout << "hate ";
        else
            cout << "love ";
        
        if ( i == n - 1 )
            cout << "it";
        else
            cout << "that ";
    }

    return 0 ;
}