#include <stdio.h>

int main()
{
    int n , ans = 0;
    scanf( "%d" , &n );
    for ( int i = 0 ; i < n ; i++ )
    {
        char c[4];
        scanf( "%s" , c );
        if ( c[1] == '+' )
            ans++;
        else
            ans--;
    }
    printf("%d\n", ans);
}