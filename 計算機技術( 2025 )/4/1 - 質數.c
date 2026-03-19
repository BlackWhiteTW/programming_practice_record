#include <stdio.h>
#include <math.h>

int main()
{
    long long int n , ans = 0 , a = 2;
    printf("Please input a number: ");
    scanf("%lld" , &n);
    while ( a <= n )
    {
        for ( long long int i = 2 ; i <= (int)sqrt(a) + 1; i++ )
        {
            if ( i == (int)sqrt(a) + 1 )
            {
                ans++;
                if ( ans == 1)
                    printf("%lld" , a );
                else
                    printf(", %lld" , a );
            }
            else if ( a % i == 0 )
                break;
        }
        a++;
    }
    printf("\nTotal is %lld\n", ans );
}