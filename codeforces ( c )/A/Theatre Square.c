#include <stdio.h>

int main()
{
    long long n , m , a , ans = 0;
    scanf( "%lld %lld %lld" , &n , &m , &a );
    if ( n % a != 0)
        n += a - n % a;
    if ( m % a != 0 )
        m += a - m % a;
    ans = n / a * ( m / a );
    printf( "%lld\n" , ans );
}