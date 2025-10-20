#include <stdio.h>

void dfs( int d, int a, int b )
{
    if ( d == 0 )
    {
        printf("%d : %d\n", a, b);
        return;
    }
    else
        dfs( --d , b , a + b );
}

int main()
{
    int n , m;
    scanf("%d", &n);
    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d", &m);
        dfs(m , 0 , 1);
    }
}