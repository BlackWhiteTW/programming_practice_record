#include <stdio.h>
#include <math.h>

int main()
{
    long long n , ans = 0 , a = 23 , tmp = 23;
    printf("Please input a number: ");
    scanf("%lld" , &n);

    while ( a <= n )
    {
        for ( long long i = 2 ; i <= (int)sqrt(a) + 1; i++ )
        {
            if ( i == (int)sqrt(a) + 1 && i - tmp > 4 )
            {
                for ( int j = tmp + 1 ; j < a-4 ; j++ )
                {
                    printf("(%d,%d,%d,%d)", j , j+1 , j+2 , j+3);
                    ans++;
                }
                tmp = a;
            }
            else if ( a % i == 0 )
                break;
        }
    }
}