#include<stdio.h>

// 定義一個結構儲存 a 和 a 的位置
typedef struct
{
    int a;
    int index;
} fix_a_index;

// 計算要減多少 以及這個數是第幾位
fix_a_index fix( int a , int b , int n , int count )
{
    fix_a_index reply;
    if ( n < b || n == a )
    {
        reply.a = a;
        reply.index = count;
        return reply;
    }
    return fix( b , a + b , n , count + 1 );
}

int main()
{
    int n;
    scanf( "%d" , &n );
    for ( int i = 1 ; i <= n ; i++ )
    {
        int num;
        scanf( "%d" , &num );
        int temp_num = num, len = 0 , arr[100] = {0};
        while ( temp_num )
        {
            fix_a_index temp = fix( 1 , 2 , temp_num , 0 );
            arr[ temp.index ] = 1;
            temp_num -= temp.a;
            len = temp.index > len ? temp.index : len;
        }
        printf( "%d = " , num );
        for ( int j = len ; j >= 0 ; j-- )
            printf( "%d" , arr[j] );
        printf( " (fib)\n" );
    }
}