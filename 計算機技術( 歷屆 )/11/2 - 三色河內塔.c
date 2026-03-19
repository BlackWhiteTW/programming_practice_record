#include <stdio.h>

long long steps = 0;

// 河內塔：把 n 個盤從 f 移到 t，使用 a 作為輔助
void hanoi_std( int n, char f, char a, char t )
{
    if ( n == 0 )
        return;

    hanoi_std( n - 1 , f , t , a );
    printf( "%d : %c -> %c\n" , n , f , t );
    steps++;
    hanoi_std( n - 1 , a , f , t );
}

// 分散：mod 3 = 1 到 A , 2 到 B , 0 到 C
void distribute( int n , char f , char roll[] , int roll_len )
{
    if ( n == 0 ) 
        return;

    // 目的
    char t = roll[ n % roll_len ];

    // 這層正確 則處理上一層 這層結束
    if ( f == t )
    {
        distribute( n - 1 , f , roll , roll_len );
        return;
    }

    // 找出 暫存（ 非位置和目的 ）
    char a = 'A' + 'B' + 'C' - f - t;

    hanoi_std( n - 1 , f , t , a );
    printf( "%d : %c -> %c\n" , n , f , t );
    steps++;
    distribute( n - 1 , a , roll , roll_len );
}

int main()
{
    int n;
    if ( scanf( "%d" , &n ) != 1 || n <= 0 )
        return 0;
    
    // 放到哪幾個柱子
    char roll[] = { 'A' , 'B' , 'C'};

    // 有 n 個盤子 從 A 分散至 roll_len 個柱子
    distribute( n , 'A' , roll , 3 );

    printf( "Total steps = %lld\n" , steps );
    return 0;
}