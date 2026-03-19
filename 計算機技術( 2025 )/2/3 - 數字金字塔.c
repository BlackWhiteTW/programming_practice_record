#include <stdio.h>

int main()
{
    int n;
    printf("Please input a number:");
    scanf("%d", &n);
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = 1 ; j <= n - i ; j++ )
            printf( " " );
        for ( int k = 0 ; k <  i  * 2 - 1 ; k++ )
            printf( "%d" , i % 10 );
        printf( "\n" );
    }
}