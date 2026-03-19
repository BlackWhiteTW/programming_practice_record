#include <stdio.h>

int ipow( int i , int n )
{
    int ans = 1;
    for ( int j = 0 ; j < i ; j++ )
        ans *= n;

    return ans;
}

int main()
{
    printf( "Please input a number: " );
    int n , i = 0 , ans = 0;
    scanf( "%d" , &n );
    while ( i++ < n )
    {
        int temp = i , index = 0 ;
        while ( temp != 0 )
        {
            temp /= 10;
            index++;
        }
        if ( index % 2 != 0 )
            continue;
        int t1 = i / ipow( index / 2 , 10 ),
            t2 = i % ipow( index / 2 , 10 );
        temp = t1 + t2;
        temp = ipow( 2 , temp );
        if ( temp != i )
            continue;
        printf( "%d, " , i );
        ans++;
    }
    printf( "\nTotal is %d\n" , ans );
}