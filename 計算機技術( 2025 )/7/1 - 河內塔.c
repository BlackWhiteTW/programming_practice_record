#include<stdio.h>

int tap = 0;

void h( int n , char f , char a , char t )
{
    if ( n == 1 )
    {
        printf( "ring %d: %c => %c\n" , n , f , t );
        tap++;
    }
    else
    {
        h( n - 1 , f , t , a );
        h( 1 , f , a , t );
        h( n - 1 , a , f , t );
    }
}

int main()
{
    int n;
    scanf( "%d" , &n );
    h( n , 'A' , 'B' , 'C' );
    printf( "%d\n" , tap );
}