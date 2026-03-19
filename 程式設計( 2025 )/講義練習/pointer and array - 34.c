#include<stdio.h>

int main()
{
    int *p;
    int a[10][10] = {0};
    for ( p = &a[0][0] ; p <= &a[9][9] ; p++ )
    {
        (*p) = ( ( p - &a[0][0] ) % 11 ) ? 0 : 1;
    }

    for ( p = &a[0][0] ; p <= &a[9][9] ; p++ )
    {
        printf( "%d " , *p );
        if ( ( p - &a[0][0] + 1 ) % 10 == 0 )
            printf( "\n" );
    }
}