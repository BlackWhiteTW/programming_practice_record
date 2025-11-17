#include <stdio.h>

void sort( int *arr , int n )
{
    for ( int i = 0 ; i < n - 1 ; i++ )
        for ( int j = i + 1 ; j < n ; j++ )
            if ( *( arr + i ) > *( arr + j ) )
            {
                *( arr + i ) += *( arr + j );
                *( arr + j ) = *( arr + i ) - *( arr + j );
                *( arr + i ) = *( arr + i ) - *( arr + j );
            }
}

int main()
{
    int n;
    printf( "請輸入整數的個數 : " );
    scanf( "%d" , &n );
    int arr[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        printf( "請輸入第 %d 個數 : " , i + 1 );
        scanf( "%d" , &arr[i] );
    }

    sort( arr, n );

    printf( "排序後的結果 : " );
    for ( int i = 0 ; i < n ; i++ )
        printf( "%d " , arr[i] );
    printf( "\n" );

    return 0;
}