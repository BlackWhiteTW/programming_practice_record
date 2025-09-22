#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Please input a number:");
    scanf("%d", &n);
    for ( int i = 1 ; i < n + 1 ; i++ )
    {
        for ( int j = 1 ; j < n - i + 1; j++ )
            printf( " " );
        for ( int k = 0 ; k < ( i - 1 ) * 2 + 1 ; k++ )
            printf( "%d" , i%10 );
        printf( "\n" );
    }
    
    system("pause");
    return 0;
}