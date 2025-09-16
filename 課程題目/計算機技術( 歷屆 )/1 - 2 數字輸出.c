#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;

    printf( "Please input a positive integer: " );
    scanf("%d", &i);

    if ( i < 1 )
        printf( "%d is not a positive integer!!\n", i );
    else if ( i < 10 )
        printf( "%d is a small integer.\n", i );
    else if ( i < 100 )
    {
        printf( "%d 的十位數為 %d\n", i, i / 10 );
        printf( "%d 的個位數為 %d\n", i, i % 10 );
    }
    else
    {
        printf( "%d is a large integer.\n", i );
        switch ( i % 5 )
        {
            case 0:
                printf( "%d is divisible by 5.\n", i );
                break;
            case 1:
                printf( "%d+5=%d\n", i, i + 5 );
                break;
            case 2:
                printf( "%d-5=%d\n", i, i - 5 );
                break;
            case 3:
                printf( "%d*5=%d\n", i, i * 5 );
                break;
            case 4:
                printf( "%d/5=%.2f\n", i, i / 5.0 );
                break;
        }
    }

    system("pause");
    return 0;
}