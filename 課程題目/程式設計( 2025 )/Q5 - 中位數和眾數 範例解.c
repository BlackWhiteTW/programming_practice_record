#include<stdio.h>

#define MAX_SIZE 100000

int main()
{
    int t , index = 0 , max = 0;
    int a[MAX_SIZE] = {0} , b[MAX_SIZE] = {0};

    // 讀取資料
    scanf( "%d" , &t );
    for ( int i_t = 0 ; i_t < t ; i_t++ )
    {
        int array_len;
        scanf( "%d" , &array_len );
        for ( int i = 0 ; i < array_len ; i++ )
        {
            int number;
            scanf( "%d" , &number );
            a[index] = number;
            index++;
        }
    }

    // 排序
    for ( int i = 0 ; i < index - 1 ; i++ )
        for ( int j = i + 1 ; j < index ; j++ )
            if( a[i] > a[j] )
            {
                a[i] += a[j];
                a[j] = a[i] - a[j];
                a[i] -= a[j];
            }

    // 中位數
    if ( index % 2 != 0 )
        printf( "%d\n" , a[index / 2] );
    else
    {
        float tmp = ( a[index / 2 - 1] + a[index / 2] ) / 2.0;
        if ( tmp == ( int )tmp )
            printf( "%d\n" , ( int )tmp );
        else
            printf( "%.1f\n" , tmp );
    }

    // 次數統計
    for ( int i = 0 ; i < index ; i++ )
    {
        b[a[i]]++;
        if ( b[a[i]] > max )
            max = b[a[i]];
    }

    // 眾數
    for ( int i = 0 ; i < MAX_SIZE ; i++ )
        if ( b[i] == max )
            printf( "%d " , a[i] );
    printf( "\n" );
}