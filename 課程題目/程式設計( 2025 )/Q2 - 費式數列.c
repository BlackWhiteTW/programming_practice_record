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
    int n;
    scanf("%d", &n);
    dfs(n , 0 , 1);
}