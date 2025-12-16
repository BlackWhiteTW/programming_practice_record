#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int t = 1 ;
    while ( 1 )
    {
        int a , b;
        scanf( "%d %d" , &a , &b );
        if ( a == 0 && b == 0 )
            return 0;
        int array[a][b];
        for ( int i = 0 ; i < a ; i++ )
            for ( int j = 0 ; j < b ; j++ )
                array[i][j] = 0;

        char c;
        getchar();
        for ( int i = 0 ; i < a ; i++ )
        {
            for ( int j = 0 ; j < b ; j++ )
            {
                c = getchar();
                if ( c == '*' )
                {
                    array[i][j] = -9;
                    for ( int x = i - 1 ; x <= i + 1 ; x++ )
                        for ( int y = j - 1 ; y <= j + 1 ; y++ )
                            if ( x >= 0 && x < a && y >= 0 && y < b )
                                array[x][y]++;
                }
            }
            getchar();
        }

        printf( "Field #%d:\n" , t++ );
        for ( int i = 0 ; i < a ; i++ )
        {
            for ( int j = 0 ; j < b ; j++ )
            {
                if ( array[i][j] < 0 )
                    printf( "*" );
                else
                    printf( "%d" , array[i][j] );
            }
            printf( "\n" );
        }
    }
    
}