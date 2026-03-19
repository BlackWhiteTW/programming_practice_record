#include <stdio.h>

int aaa( int n )
{
    if ( n < 1 )
        return 0;
    else
        return aaa( n - 1 ) + n;
}

int main()
{
    int n;
    scanf( "%d" , &n );
    for ( int i = 1 ; i <= n ; i++ )
    {
        int x1 , y1 , x2 , y2 ;
        scanf( "%d %d %d %d" , &x1 , &y1 , &x2 , &y2 );
        int n1 = aaa( x1 + y1 ) , n2 = aaa( x2 + y2 ) ;
        n1 += x1 ; n2 += x2 ;
        printf( "Case %d : %d\n" , i , n2 - n1 );
    }
}