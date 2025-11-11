#include<stdio.h>

void input_number( int arr[] , int *len )
{
    while ( 1 )
    {
        arr[ *len ] = getchar() - '0';
        if ( arr[ *len ] == '\n' - '0' )
            break;
        ( *len )++;
    }
}

void multiply_arrays( int a[] , int b[] , int c[] , int len_a , int len_b )
{
    for ( int i = 0 ; i < len_a ; i++ )
        for ( int j = 0 ; j < len_b ; j++ )
            c[ i + j + 1 ] += a[i] * b[j];
}

void carry_array( int c[] , int c_len )
{
    for ( int i = c_len - 1 ; i > 0 ; i-- )
    {
        c[i-1] += c[i] / 10;
        c[i] = c[i] % 10;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    
    for (int i = 0; i < t; i++)
    {
        int a[512] = {0} , b[512] = {0} , c[1024] = {0};
        int not_carry = 1 , len_a = 0 , len_b = 0 , max_len = 0;

        input_number(a, &len_a);
        input_number(b, &len_b);

        not_carry = ( a[0] * b[0] / 10 ) ? 0 : 1;
        max_len = len_a + len_b - not_carry;

        multiply_arrays(a, b, c, len_a, len_b);
        carry_array(c, max_len);

        for ( int j = not_carry ; j < max_len ; j++ )
            printf("%d", c[j]);
        printf("\n");
    }
}