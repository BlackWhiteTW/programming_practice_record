#include<stdio.h>
#include<math.h>

int is_prime( int num )
{
    for ( int i = 2 ; i <= sqrt( num ) ; i++ )
    {
        if ( num % i == 0 )
            return 0;
    }
    return 1;
}

int main()
{
    int n , count = 0;
    printf( "Please input a number: " );
    scanf( "%d" , &n );
    for ( int i = 3 ; i <= n - 2 ; i++ )
    {
        if ( is_prime( i ) && is_prime( i + 2 ) )
        {
            printf( "(%d , %d) " , i , i + 2 );
            count++;
        }
    }
    printf( "\nTotal is %d" , count );
}