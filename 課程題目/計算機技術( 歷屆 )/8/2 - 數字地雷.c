#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_num ()
{
    int tmp = rand() % 100 ;
    if ( tmp > 11 && tmp < 41 )
        return tmp;
    else
        return random_num();
}

int main()
{
    srand(time(NULL));
    int n = random_num();

    printf("N=%d\n", n);

    int sum = 0;
    while (sum < n)
    {
        int tmp;
        if ( sum == 0 )
            tmp = 3;
        else
            tmp = 3 - sum % 4;
        printf("Sum=%d, Computer add %d\n", sum, tmp);
        sum += tmp;
        printf("Sum=%d, You add: ", sum);
        scanf("%d", &tmp);
        sum += tmp;
        if ( sum >= n )
        {
            printf("You lose!!\n");
            break;
        }
    }
    
}