#include <stdio.h>

int max_len = 0 , add = 1;

void input_number( int arr[] , int *len )
{
    while( 1 )
    {
        arr[ *len ] = getchar() - '0';
        if ( arr[ *len ] == '\n' - '0' )
            break;
        ( *len )++;
    }
}

void move_array( int arr[] , int len )
{
    for ( int i = len ; i < max_len ; i++ )
    {
        for ( int j = i ; j >= 0 ; j-- )
            arr[j+1] = arr[j];
        arr[0] = 0;
    }
}

void add_arrays( int a[] , int b[] , int c[] )
{
    for ( int i = 0 ; i < max_len ; i++ )
    {
        c[i+1] = a[i] + b[i];
        if ( c[i+1] >= 10 )
        {
            c[i+1] -= 10;
            c[i]++;
        }
    }
}

int main()
{
    int a[1024] = {0} , b[1024] = {0} , c[1024] = {0};
    int len_a = 0 , len_b = 0 , t = 0;

    scanf("%d" , &t );
    getchar();

    for ( int t_i = 0 ; t_i < t ; t_i++ )
    {
        len_a = 0 , len_b = 0 , add = 1;

        input_number( a , &len_a );
        input_number( b , &len_b );

        max_len = ( len_a > len_b ) ? len_a : len_b;
        move_array( a , len_a );
        move_array( b , len_b );

        add_arrays( a , b , c );

        if ( c[0] != 0 )
            add = 0;

        for ( int i = add ; i <= max_len ; i++ )
            printf( "%d" , c[i] );
        printf("\n");
    }
}