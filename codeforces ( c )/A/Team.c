#include <stdio.h>

int main()
{
    int n , ans = 0;
    scanf( "%d" , &n);
    for ( int i = 0; i < n; i++)
    {
        int x , y , z;
        scanf( "%d %d %d" , &x , &y , &z );
        if ( x + y + z >= 2 )
            ans++;
    }
    printf("%d\n", ans);
}