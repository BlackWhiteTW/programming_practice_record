#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0 , a = 0 , b = 0 , c = 0;
    printf("Please input a number:");
    scanf("%d", &n);
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( i == n )
            printf("%d\n", b );
        else
            printf("%d, ", b );
        if ( b == 0 )
            b++;
        else
        {
            c = a + b;
            a = b;
            b = c;
        }
    }

    system("pause");
    return 0;
}