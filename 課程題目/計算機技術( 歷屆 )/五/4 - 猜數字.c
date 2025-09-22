#include <stdio.h>
#include <time.h>

int main()
{
    char n[4] , ans[5];
    int t = 0 , a , b ;
    srand(time(NULL));
    for ( int i = 0 ; i < 4 ; i++ )
    {
        n[i] = rand() % 10 + '0';
        for ( int j = 0 ; j < i ; j++ )
        {
            if ( n[i] == n[j] )
            {
                i--;
                break;
            }
        }
    }
    printf("Answer: %s\n" , n);

    while ( 1 )
    {
        a = 0 , b = 0;
        printf("Please input four digits (0~9): ");
        scanf("%s" , ans);
        for ( int i = 0 ; i < 4 ; i++ )
        {
            if ( ans[i] == n[i] )
                a++;
            for ( int j = 0 ; j < 4 ; j++ )
            {
                if ( n[i] == ans[j] && i != j )
                {
                    b++;
                    continue;
                }
            }
        }
        t++;
        if ( a == 4 )
        {
            printf("You got it!! %d times!!\n" , t);
            break;
        }
        else
            printf("You got %dA %dB\n" , a , b);
    }
    
}