#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    scanf( "%d" , &n );
    int *array , *array_a , *array_b;
    array = ( int* )calloc( n , sizeof( int ) );
    array_a = ( int* )calloc( n , sizeof( int ) );
    array_b = ( int* )calloc( n , sizeof( int ) );
    for ( int i = 0 ; i < n ; i++ )
        scanf( "%d" , &array[i] );
    int a_index = n - 1 , b_index = 0;
    int t = 0 , stack_index = 0 , point = 0;
    for ( int i = 0 ; i < n ; i++ )
        array_a[i] = array[n - 1 - i];

    for ( int i = 0 ; i < n - 1 ; i++ )
        for ( int j = i + 1 ; j < n ; j++ )
            if ( array[i] > array[j] )
            {
                array[i] += array[j];
                array[j] = array[i] - array[j];
                array[i] -= array[j];
            }

    while ( stack_index < n )
    {
        int f = array[stack_index];
        for ( int i = 0 ; i < n ; i++ )
            if ( f == array_a[i] )
                point = 1;

        if ( point )
        {
            while ( array_a[a_index] != f )
            {
                array_b[b_index++] = array_a[a_index--];
                array_a[a_index + 1] = 0;
                t++;
            }
            for ( int i = a_index ; i < n ; i++ )
                array_a[i] = array_a[i + 1];
            array_a[n-1] = 0;
        }
        else
        {
            while ( array_b[b_index] != f )
            {
                array_a[a_index++] = array_b[b_index--];
                array_b[b_index + 1] = 0;
                t++;
            }
            for ( int i = b_index ; i < n ; i++ )
                array_b[i] = array_b[i + 1];
            array_b[n-1] = 0;
        }
        stack_index++;
        point = 0;
    }
    free( array );
    free( array_a );
    free( array_b );

    printf( "%d\n" , t );
}