#include<stdio.h>

int main()
{
    int a , b , t = 1;
    while ( 1 )
    {
        scanf ( "%d %d" , &a , &b );
        if ( a == 0 && b == 0 )
            return 0;
        int arr_a[a] , arr_b[b];
        for ( int i = 0 ; i < a ; i++ )
            scanf ( "%d" , &arr_a[i] );
        for ( int j = 0 ; j < b ; j++ )
            scanf ( "%d" , &arr_b[j] );
        
        int index_a = 0 , index_b = 0 , count = 0 , min_len = ( a < b ) ? a : b , flag_a , flag_b;
        for ( int i = 0 ; i < min_len ; i = ( index_a < index_b ) ? index_b : index_a )
        {
        }
        printf( "Twin Towers #%d\n" , t++ );
        printf( "Number of Tiles : %d\n\n" , count );
    }
}