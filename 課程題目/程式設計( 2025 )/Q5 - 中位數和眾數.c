#include<stdio.h>

// 判斷是否出現過
void input_number( int a[] , int b[] , int *max_index , int number )
{
    for ( int i = 0 ; i < *max_index ; i++ )
    {
        if ( a[i] == number )
        {
            b[i] ++;
            return;
        }
    }
    a[ *max_index ] = number;
    b[ *max_index ] ++;
    (*max_index) ++;
    return;
}

// 排序 A B
void sort_two_array( int a[] , int b[] , int len )
{
    for ( int i = 0 ; i < len ; i++ )
    {
        for ( int j = i + 1 ; j < len ; j++ )
        {
            if ( a[i] > a[j] )
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
}

// 中位數
void median( int a[] , int b[] , int len , int number )
{
    int index = 0;
    if ( len %2 != 0 )
    {
        for ( int i = 0 ; i < len ; i++ )
        {
            index += b[i];
            if ( index >= ( number / 2 ) + 1 )
            {
                printf( "%d\n" , a[i] );
                break;
            }
        }
    }
    else
    {
        float tmp = 0;
        for ( int i = 0 ; i < len ; i++ )
        {
            index += b[i];
            if ( index >= ( number / 2 ) )
            {
                tmp += ( float )a[i];
                break;
            }
        }
        index = 0;
        for ( int i = 0 ; i < len ; i++ )
        {
            index += b[i];
            if ( index >= ( number / 2 ) + 1 )
            {
                tmp += ( float )a[i];
                break;
            }
        }
        tmp /= 2.0;
        if ( tmp == ( int )tmp )
            printf( "%d\n" , ( int )tmp );
        else
            printf( "%.1f\n" , tmp );
    }
}

// 眾數
void mode( int a[] , int b[] , int len )
{
    int max = 0 , mode_index = 0 , max_number[len] = {0};
    for ( int i = 0 ; i < len ; i++ )
    {
        if ( b[i] > max )
        {
            max = b[i];
            mode_index = 0;
            max_number[mode_index] = a[i];
        }
        else if ( b[i] == max )
        {
            mode_index ++;
            max_number[mode_index] = a[i];
        }
    }
    for ( int i = 0 ; i <= mode_index ; i++ )
    {
        printf( "%d" , max_number[i] );
        if ( i != mode_index )
            printf( " " );
    }
    printf( "\n" );
}

int main()
{
    int t , index = 0 , all = 0;
    scanf( "%d" , &t );
    int a[5000] = {0} , b[5000] = {0};

    for ( int i_t = 0 ; i_t < t ; i_t++ )
    {
        int array_len;
        scanf( "%d" , &array_len );
        for ( int i = 0 ; i < array_len ; i++ )
        {
            int number;
            scanf( "%d" , &number );
            input_number( a , b , &index , number );
            all++;
        }
    }

    sort_two_array( a , b ,index );

    median( a , b , index , all );

    mode( a , b , index );
}