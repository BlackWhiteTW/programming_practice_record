#include<stdio.h>

int max_len;

// 輸入 A B 大數內容
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

// 將數字往後移動對齊
void move_array( int arr[] , int len )
{
    for ( int i = len ; i < max_len ; i++ )
    {
        for ( int j = i ; j >= 0 ; j-- )
            arr[j+1] = arr[j];
        arr[0] = 0;
    }
}

// 比較 A B 大小 ( 判斷是否可除 )
int compare_arrays( int a[] , int b[] )
{
    for ( int i = 0 ; i < max_len ; i++ )
    {
        if ( a[i] > b[i] )
            return 1;
        else if ( a[i] < b[i] )
            return 0;
    }
    return 1;
}

// 減法 A - B
void sub_arrays( int a[] , int b[] )
{
    int c[1024] = {0};
    for ( int i = 0 ; i < max_len ; i++ )
    {
        c[i+1] = a[i] - b[i];
        if ( c[i+1] < 0 )
        {
            c[i+1] += 10;
            c[i]--;
        }
    }
    for ( int j = 1 ; j < max_len + 1; j++ )
        a[j-1] = c[j];
}


int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    for ( int i_t = 0 ; i_t < t ; i_t++ )
    {
        int a[1024] = {0} , b[1024] = {0} , c[1024] = {0};
        int len_a = 0 , len_b = 0 , len_c = 0 , zero = 1;

        input_number( a , &len_a );
        input_number( b , &len_b );

        max_len = ( len_a > len_b ) ? len_a : len_b;
        move_array( a , len_a );
        move_array( b , len_b );

        while ( compare_arrays( a , b ) )
        {
            sub_arrays( a , b );
            c[0]++;
            for ( int j = 0 ; j < max_len ; j++ )
            {
                if ( c[j] >= 10 && c[j+1] == 0 )
                    len_c++;
                if ( c[j] >= 10 )
                {
                    c[j] -= 10;
                    c[j+1]++;
                }
            }
        }

        for ( int j = len_c ; j >= 0 ; j-- )
            printf( "%d" , c[j] );
        printf( "\n" );

        for ( int j = 0 ; j < max_len ; j++ )
        {
            if ( a[j] == 0 && zero == 1 )
            {
                zero = 0;
                continue;
            }
            printf( "%d" , a[j] );
        }
        printf( "\n" );
    }
}