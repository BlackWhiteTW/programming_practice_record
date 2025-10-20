#include <stdio.h>

int main()
{
    int n , m;
    scanf("%d", &n);
    for ( int i = 0 ; i < n ; i++ )
    {
        scanf("%d", &m);
        int a = 0 , b = 1;
        for ( int i = 1 ; i <= m ; i++ )
            b += a , a = b - a;
        printf("%d:%d\n", a, b );
    }
}