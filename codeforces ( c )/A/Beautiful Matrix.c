#include <stdio.h>
#include <math.h>

int main()
{
    int ans = 0 ;
    for ( int i = 0 ; i < 5 ; i++ )
    {
        for ( int j = 0 ; j < 5 ; j++ )
        {
            int t;
            scanf( "%d" , &t );
            if ( t == 1 )
                ans = abs(2 - i) + abs(2 - j);
        }
    }
    printf("%d\n", ans);
}