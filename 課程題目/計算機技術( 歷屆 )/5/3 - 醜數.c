#include <stdio.h>

int main()
{
    int n , tmp = 1 , time = 1 , mod = 0;
    printf("Please input a number: ");
    scanf("%d", &n);
    while ( mod < n )
    {
        tmp = time;
        while( tmp % 2 == 0 )
            tmp /= 2;
        while (tmp % 3 == 0)
            tmp /= 3;
        while (tmp % 5 == 0)
            tmp /= 5;
        if ( tmp == 1 )
        {
            if ( mod == 0 )
                printf("%d", time);
            else
                printf(", %d", time);
            mod++;
        }
        time++;
    }
    
}