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

// 找出陣列中第一個非零位址
int first_nonzero( int arr[] )
{
    for ( int i = 0 ; i < max_len ; i++ )
        if ( arr[i] != 0 )
            return i;
    return max_len;
}

// 將陣列左移 ( * 10^N )
void shift_array( int src[] , int shift , int dest[] )
{
    for ( int i = 0 ; i < max_len ; i++ )
        dest[i] = 0;
    for ( int i = 0 ; i < max_len ; i++ )
    {
        int target = i - shift;
        if ( target >= 0 )
            dest[target] = src[i];
    }
}

// 陣列乘以單一數字
void mul_array_digit( int src[] , int digit , int dest[] )
{
    int carry = 0;
    for ( int i = max_len - 1 ; i >= 0 ; i-- )
    {
        int value = src[i] * digit + carry;
        dest[i] = value % 10;
        carry = value / 10;
    }
}

// 減法 A - B ( 就地修改 A 陣列 )
void sub_array_inplace( int a[] , const int b[] )
{
    for ( int i = max_len - 1 ; i >= 0 ; i-- )
    {
        int diff = a[i] - b[i];
        if ( diff < 0 )
        {
            int k = i - 1;
            while ( k >= 0 && a[k] == 0 )
            {
                a[k] = 9;
                k--;
            }
            if ( k >= 0 )
                a[k]--;
            diff += 10;
        }
        a[i] = diff;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    for ( int i_t = 0 ; i_t < t ; i_t++ )
    {
        int a[1024] = {0} , b[1024] = {0} , c[1024] = {0};
        int len_a = 0 , len_b = 0;

        input_number( a , &len_a );
        input_number( b , &len_b );

        max_len = ( len_a > len_b ) ? len_a : len_b;
        move_array( a , len_a );
        move_array( b , len_b );

        while ( compare_arrays( a , b ) )
        {
            int pos_a = first_nonzero( a );
            int pos_b = first_nonzero( b );
            if ( pos_a == max_len )
                break;

            // 計算差 10 的 N 次方
            int shift = pos_b - pos_a;
            if ( shift < 0 )
                shift = 0;

            // 移動並紀錄
            int shift_b[1024] = {0};
            shift_array( b , shift , shift_b );

            // 如果移動太多 則減少移動
            while ( shift > 0 && !compare_arrays( a , shift_b ) )
            {
                shift--;
                shift_array( b , shift , shift_b );
            }

            int product[1024] = {0};
            int low = 1 , high = 9 , best = 0;
            while ( low <= high )
            {
                int mid = ( low + high ) >> 1;
                mul_array_digit( shift_b , mid , product );
                if ( compare_arrays( a , product ) )
                {
                    best = mid;
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }

            if ( best == 0 )
                break;

            mul_array_digit( shift_b , best , product );
            sub_array_inplace( a , product );

            c[shift] += best;
            for ( int j = shift ; j < 1023 ; j++ )
            {
                if ( c[j] >= 10 )
                {
                    c[j+1] += c[j] / 10;
                    c[j] %= 10;
                }
                else
                    break;
            }
        }

        // 輸出
        int top = 1023;
        while ( top > 0 && c[top] == 0 )
            top--;
        if ( top == 0 && c[0] == 0 )
            printf( "0\n" );
        else
        {
            for ( int j = top ; j >= 0 ; j-- )
                printf( "%d" , c[j] );
            printf( "\n" );
        }

        int rem_start = first_nonzero( a );
        if ( rem_start == max_len )
            printf( "0\n" );
        else
        {
            for ( int j = rem_start ; j < max_len ; j++ )
                printf( "%d" , a[j] );
            printf( "\n" );
        }
    }
}