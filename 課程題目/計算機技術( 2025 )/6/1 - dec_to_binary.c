#include <stdio.h>

long long int pow_int ( int b , int e )
{
    long long int result = 1;
    for ( int i = 0 ; i < e ; i++ )
        result *= b;
    return result;
}

void d_to_b ( long long int dec_num , int binary_arr[] , int *size )
{
    binary_arr[*size] = dec_num % 2;
    (*size)++;
    if ( dec_num / 2 != 0 )
        d_to_b ( dec_num / 2 , binary_arr , size );
    else
    {
        for ( int j = *size - 1 ; j >= 0 ; j-- )
            printf("%d", binary_arr[j]);
        printf("\n");
        return;
    }
}

void b_to_d ( int binary_arr[] , long long int *dec_num , int size , int index )
{
    if ( size == 0 )
    {
        printf("%lld\n", *dec_num);
        return;
    }
    *dec_num += binary_arr[ index ] * pow_int ( 2 , --size );
    b_to_d ( binary_arr , dec_num , size , index + 1);
}

int main()
{
    long long int dec_num = 0;
    int binary_arr[64] = {0}, i = 0;

    printf("Please input a decimal number: ");
    scanf("%lld", &dec_num);
    d_to_b ( dec_num , binary_arr , &i );

    binary_arr[64] = {0} , dec_num = 0 , i = 0;
    printf("Please input a binary number: ");

    getchar();
    while( 1 )
    {
        binary_arr[i] = getchar() - '0';
        if ( binary_arr[i] == '\n' - '0' )
            break;
        i++;
    }
    b_to_d ( binary_arr , &dec_num , i , 0 );
}