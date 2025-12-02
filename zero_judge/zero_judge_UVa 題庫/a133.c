#include<stdio.h>

int main()
{
    int a , b , t = 1;
    while ( 1 )
    {
        scanf ( "%d %d" , &a , &b );
        if ( a == 0 && b == 0 )
            return 0;

        int arr_a[a+1] , arr_b[b+1] , arr_c[a+1][b+1] , count = 0;
        for ( int i = 1 ; i <= a ; i++ )
            scanf ( "%d" , &arr_a[i] );
        for ( int j = 1 ; j <= b ; j++ )
            scanf ( "%d" , &arr_b[j] );

        for ( int i = 0 ; i <= a ; i++ )
            for ( int j = 0 ; j <= b ; j++ )
                arr_c[i][j] = 0;

        for ( int i = 1 ; i <= a ; i++ )
            for ( int j = 1 ; j <= b ; j++ )
            {
                if ( arr_a[i] == arr_b[j] )
                    arr_c[i][j] = arr_c[i-1][j-1] + 1;
                else
                    arr_c[i][j] = ( arr_c[i-1][j] > arr_c[i][j-1] ) ? arr_c[i-1][j] : arr_c[i][j-1];
            }

        printf ( "Twin Towers #%d\n" , t++ );
        printf ( "Number of Tiles : %d\n\n" , arr_c[a][b] );
    }
}