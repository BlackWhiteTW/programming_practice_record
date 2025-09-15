#include <stdio.h>

int main()
{
    int k , n , w , ans ;
    scanf( "%d %d %d" , &k , &n , &w );
    ans = k * w * ( w + 1 ) / 2 - n ;
    if ( ans < 0 )
        ans = 0;
    printf("%d\n", ans);
}