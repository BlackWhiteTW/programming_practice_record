#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n ; 
    cin >> n ;
    char a[n] ;
    for ( int i = 0 ; i < n ; i++ )
        cin >> a[i] ;

    transform(a, a + n, a, ::tolower);

    char c[26] = { 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z' } ;
    bool f[26] = { false } ;

    for ( int i = 0 ; i < n ; i++ )
        for ( int j = 0 ; j < 26 ; j++ )
            if ( a[i] == c[j] )
                f[j] = true ;

    if ( count( f , f + 26 , true ) == 26 )
        cout << "YES" << endl ;
    else
        cout << "NO" << endl ;
    return 0 ;
}