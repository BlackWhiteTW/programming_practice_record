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

// 奇偶分散
void distribute( int n , char f , char a , char t )
{
    if ( n == 0 ) 
        return;

    // 目的
    if ( n % 2 == 0 )
        t = 'C';
    else
        t = 'B';

    // 這層正確 則處理上一層 這層結束
    if ( f == t )
    {
        if ( f != 'A' )
            a = 'A';
        distribute( n - 1 , f , a , t );
        return;
    }

    hanoi_std( n - 1 , f , t , a );
    printf( "%d : %c -> %c\n" , n , f , t );
    steps++;
    distribute( n - 1 , a , t , f );
}

int main()
{
    int n;
    if ( scanf( "%d" , &n ) != 1 || n <= 0 )
        return 0;

    distribute( n , 'A' , 'B' , 'C' );
    printf( "Total steps = %lld\n" , steps );
    return 0;
}