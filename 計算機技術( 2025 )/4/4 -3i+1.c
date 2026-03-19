#include <stdio.h>

int i3( int a , int b )
{
    if ( a % 2 == 0 )
        a /= 2;
    else
        a = a * 3 + 1;
    b += a ;
    if ( a == 1 )
        return b;
    else
        i3 ( a , b );
}

int max( int a , int b )
{
    if ( a > b )
        return a;
    else
        return b;
}

int main()
{
    int n1 , n2 , tmp , sum = 0 , index = 0 ;
    printf( "Please input the LowerBound and the UpperBound: " );
    scanf( "%d %d" , &n1 , &n2 );
    for ( ; n1 <= n2 ; n1++ )
    {
        tmp = i3( n1 , n1 );
        sum = max( tmp , sum );
        if ( tmp == sum )
            index = n1;
    }
    printf( "N = %d Sum = %d" , index , sum );
}