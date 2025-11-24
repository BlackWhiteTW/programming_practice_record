#include<stdio.h>

// 進制轉換
void d_to_b( int array[] , int dec )
{
    int index = 31;
    while ( dec )
    {
        array[index--] = dec % 2;
        dec /= 2;
    }
}

// 交換
void swap( int *a , int *b )
{
    *a += *b;
    *b = *a - *b;
    *a -= *b;
}

// 2的次方
int tow_pow( int n )
{
    int ans = 1;
    for ( int i = 0 ; i < n ; i++ )
        ans *= 2;
    return ans;
}

int main()
{
    int n;
    printf( "Please input a decimal number: ");
    scanf( "%d" , &n );

    int binary[32] = {0};

    if ( n < 0 )
        d_to_b( binary , -n - 1 );
    else
    d_to_b( binary , n );

    for ( int i = 0 ; i < 32 ; i += 8 )
        for ( int j = 0 ; j < 4 ; j++ )
            swap( &binary[i + j] , &binary[i + 4 + j] );

    int ans = 0;
    if ( n >= 0 )
    {
        for ( int i = 31 ; i >= 0 ; i-- )
            if ( binary[i] == 1 )
                ans += tow_pow( 31 - i );
    }
    else
    {
        for ( int i = 0 ; i < 32 ; i++ )
            binary[i] = 1 - binary[i];
        for ( int i = 31 ; i >= 0 ; i-- )
            if ( binary[i] == 1 )
                ans += tow_pow( 31 - i );
    }

    printf( "%d" , ans );

}