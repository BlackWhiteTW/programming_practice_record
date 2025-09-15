#include <stdio.h>

int main()
{
    int n , ans = 0 ;
    scanf( "%d" , &n );
    ans = n / 5 ;
    if ( n % 5 != 0 )
        ans++;
    printf( "%d\n" , ans );
}