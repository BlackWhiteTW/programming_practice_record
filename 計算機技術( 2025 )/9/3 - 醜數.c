#include<stdio.h>

// 計算 a 是 b 的多少倍
void while_a_b( long long int *a, int b )
{
    while ( *a % b == 0 )
    {
        *a /= b;
    }
}

int main()
{
    int n;
    printf( "Please input a number: ");
    scanf( "%d" , &n );

    long long int number = 1;
    while ( n-- )
    {
        while ( 1 )
        {
            long long int g = number;
            while_a_b( &g , 2 );
            while_a_b( &g , 3 );
            while_a_b( &g , 5 );
            if ( g == 1 )
                break;
            else
                number++;
        }
        printf( "%lld" , number );
        number++;
        if ( n != 0 )
            printf( " , " );
    }
}