#include <stdio.h>

// 交換
void swap( int *a , int *b )
{
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

// 最簡分式
int gcd( int a , int b )
{
    while ( b )
    {
        if ( a > b )
            swap( &a , &b );
        b %= a;
        if ( b == 1 || a == 1 )
            return 1;
    }
    return 0;
}

// 排序
void sort( int array[][2] , int array_len )
{
    for ( int i = 0 ; i < array_len - 1 ; i++ )
        for ( int j = i + 1 ; j < array_len ; j++ )
        {
            if ( array[i][0] * array[j][1] > array[i][1] * array[j][0] )
            {
                swap( &array[i][0] , &array[j][0] );
                swap( &array[i][1] , &array[j][1] );
            }
        }
}

int main()
{
    int n , index = 2;
    printf( "Please input a number: " );
    scanf( "%d" , &n );
    int array[ n * n / 2 ][2] = {0};

    array[0][0] = 0 , array[0][1] = 1,
    array[1][0] = 1 , array[1][1] = 1;

    for ( int i = 1 ; i <= n ; i++ )
        for ( int j = 1 ; j < i ; j++ )
        {
            if ( gcd( i , j ) )
            {
                array[index][0] = j;
                array[index][1] = i;
                index++;
            }
        }

    sort( array , index );

    for ( int i = 0; i < index; i++ )
    {
        if ( array[i][1] == 1 )
            printf( "%d" , array[i][0] );
        else
            printf( "%d/%d" , array[i][0] , array[i][1] );
        if ( array[i][0] != 1 || array[i][1] != 1 )
            printf( ", " );
    }

    printf( " (total number: %d)\n" , index );
}