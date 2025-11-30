#include<stdio.h>

int main()
{
    int n;
    scanf( "%d" , &n );
    for ( int i = 0 ; i < n ; i++ )
    {
        char www[10][1000];
        int vi[10] = {0};
        for ( int j = 0 ; j < 10 ; j++ )
            scanf( "%s %d" , www[j] , &vi[j] );
        int max = vi[0];

        for ( int j = 1 ; j < 10 ; j++ )
            if ( vi[j] > max )
                max = vi[j];

        printf( "Case #%d:\n" , i + 1 );
        for ( int j = 0 ; j < 10 ; j++ )
            if ( vi[j] == max )
                printf( "%s\n" , www[j] );
    }
}