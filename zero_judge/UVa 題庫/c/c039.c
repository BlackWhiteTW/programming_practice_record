#include<stdio.h>

int n3( int n , int len )
{
    if ( n == 1 )
        return len;
    if ( n % 2 == 0 )
        return n3( n / 2 , len + 1 );
    else
        return n3( n * 3 + 1 , len + 1 );
}

int main()
{
    int a , b;
    while ( scanf( "%d %d" , &a , &b ) != EOF )
    {
        int max = 0,
            min_n = a < b ? a : b,
            max_n = a > b ? a : b;
        for ( int i = min_n ; i <= max_n ; i++ )
            if ( n3( i , 1 ) > max )
                max = n3( i , 1 );
        printf( "%d %d %d\n" , a , b , max );
    }
}