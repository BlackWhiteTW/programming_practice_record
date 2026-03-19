#include <stdio.h>

int gcd( int a , int b )
{
    if ( a % b == 0 ) 
        return b;
    else
        return gcd( b , a % b );
}

int main()
{
    int l , w;
    printf("長方形長*寬: ");
    scanf( "%d%d" , &l , &w );
    for ( int i = 1 ; i <= gcd( l , w ) ; i++ )
    {
        if ( l % i == 0 && w % i == 0 )
        {
            int s = l * w / i / i;
            printf( "正方形邊長: %d 個數: %d\n" , i , s );
        }
    }
}