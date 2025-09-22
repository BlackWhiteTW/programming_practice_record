#include <stdio.h>

int main()
{
    int n;
    printf("Please input a number: ");
    scanf("%d" , &n);
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = n - i ; j >= 1 ; j-- )
            printf(" ");
        for ( int j = 1 ; j <= i * 2 - 1; j++ )
        {
            if ( j <= i )
                printf("%d" , j % 10);
            else
                printf("%d" , ( i * 2 - j ) % 10);
        }
        printf("\n");
    }
}