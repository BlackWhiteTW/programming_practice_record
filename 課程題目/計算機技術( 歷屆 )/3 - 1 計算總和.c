#include <stdio.h>
#include <stdlib.h>

int main()
{
    char again = 'y';
    while ( again == 'y')
    {
        int a , b ;
        printf("Number 1:");
        scanf("%d", &a);
        printf("Number 2:");
        scanf("%d", &b);
        if ( a > b )
        {
            printf("Error!! Number 1 > Number 2\n");
            continue;
        }
        int sum = 0;
        for ( int i = a; i <= b; i++)
        {
            sum += i;
        }
        printf("Sum = %d\n", sum);
        printf("Again? (Y/N):");
        scanf(" %c", &again);
        if ( again >= 'A' && again <= 'Z' )
            again += 'a' - 'A';
    }

    system("pause");
    return 0;
}