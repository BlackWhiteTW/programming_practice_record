#include <stdio.h>

int main()
{
    int n , m , ans = 0;
    scanf( "%d %d" , &n , &m );
    int a[n];
    for ( int i = 0 ; i < n ; i++ )
        scanf( "%d" , &a[i] );
    for ( int i = 0 ; i < n ; i++ )
        if ( a[i] >= a[m-1] && a[i] > 0 )
            ans++;
    printf( "%d\n" , ans );
}