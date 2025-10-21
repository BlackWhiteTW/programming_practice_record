#include <stdio.h>

int input_char_to_int_array ( int num[] )
{
    int index = 0;
    char ch;
    while ( ( ch = getchar() ) != '\n' )
        num[index++] = ch - '0';
    return index;
}

void move_back_arr ( int num[] , int *size , int times )
{
    for ( int i = 0 ; i < times ; i++ )
    {
        for ( int j = *size ; j > 0 ; j-- )
                num[j] = num[j - 1];
        num[0] = 0;
        (*size)++;
    }
}

int main()
{
    int m ;
    scanf("%d", &m);
    getchar();
    while ( m-- )
    {
        int a[400] = {0}, b[400] = {0}, c[401] = {0},
        a_size = input_char_to_int_array( a ) , b_size = input_char_to_int_array( b ),
        max_size = ( a_size > b_size ? a_size : b_size );

        if ( a_size < b_size )
            move_back_arr( a , &a_size , b_size - a_size );
        else if ( b_size < a_size )
            move_back_arr( b , &b_size , a_size - b_size );

            c[0] = ( a[0] + b[0] ) / 10;
        for ( int i = 1 ; i <= max_size ; i++ )
            c[i] += ( a[i] + b[i] ) / 10 + ( a[i - 1] + b[i - 1] ) % 10;

        for ( int index = c[0] != 0 ? 0 : 1; index <= max_size ; index++ )
            printf("%d", c[index]);
        printf("\n");
    }
}