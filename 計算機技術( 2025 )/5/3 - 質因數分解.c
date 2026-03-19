#include <stdio.h>

int main()
{
    int n;
    printf( "Please input a number n (1<n<1000000000): " );
    scanf( "%d" , &n );
    printf( "%d = " , n );
    int tmp = 0;
    for ( int i = 2 ; i < n ; i++ )
            if ( n % i == 0 )
            {
                printf( "%d *" , i );
                n /= i , i -- , tmp ++;
            }
    printf( " %d\n" , n );
}