#include <stdio.h>

int main()
{
    long long n , ans = 0 ;
    int k = 0 ;
    scanf( "%lld %d" , &n , &k );
    while ( k-- )
    {
        if ( n % 10 != 0 )
            n--;
        else
            n /= 10;
    }
    printf( "%lld\n" , n );
}