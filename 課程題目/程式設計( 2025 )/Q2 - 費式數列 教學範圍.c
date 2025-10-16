#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int a = 0 , b = 1;
    for ( int i = 1 ; i <= n ; i++ )
        b += a , a = b - a;
    printf("%d : %d\n", a, b );
}