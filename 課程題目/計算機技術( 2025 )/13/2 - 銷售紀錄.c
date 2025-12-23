#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    FILE *ptr = fopen( "課程題目\\計算機技術( 2025 )\\13\\t9.txt" , "r" );
    int t , n;
    fscanf( ptr , "%d" , &t );
    int **array = (int**)malloc( t * sizeof(int*) );
    for ( int i = 0 ; i < t ; i++ )
    {
        fscanf( ptr , "%d" , &n );
        array[i] = ( int* )malloc( ( n + 1 ) * sizeof( int ) );
        for ( int j = 0 ; j < n ; j++ )
            fscanf( ptr , "%d" , &array[i][j] );
        array[i][n] = 0;
    }
    fclose( ptr );

    int list_num = 1 , *list = NULL;
    list = ( int* )calloc( 1 , sizeof( int ) );
    for ( int i = 0 ; i < t ; i++ )
        for ( int j = 0 ; array[i][j] != 0 ; j++ )
            for ( int k = 0 ; k < list_num ; k++ )
            {
                if ( array[i][j] == list[k] )
                    break;
                if ( k == list_num - 1 )
                {
                    list_num++;
                    list = ( int* )realloc( list , list_num * sizeof( int ) );
                    list[ list_num - 1 ] = array[i][j];
                }
            }

    int table[ list_num * list_num ] = {0};
    for ( int i = 0 ; i < t ; i++ )
    {
        int temp[ list_num ] = {0};
        for ( int j = 0 ; array[i][j] != 0 ; j++ )
            temp[ array[i][j] ] = 1;
        for ( int m = 0 ; m < list_num ; m++ )
            for ( int n = m + 1 ; n < list_num ; n++ )
                if ( temp[ list[m] ] == 1 && temp[ list[n] ] == 1 )
                    table[ list_num * list[m] + list[n] ]++;
    }

    int max = 0;
    for ( int i = 0 ; i < list_num * list_num ; i++ )
        if ( table[i] > max )
            max = table[i];
    for ( int i = 0 ; i < list_num * list_num ; i++ )
        if ( table[i] == max )
            printf( "(%d , %d) %d 次\n" , i / list_num , i % list_num , max );
}