#include <stdio.h>
#include <math.h>

int prime_factorization(int n)
{
    if ( n == 2 || n == 3 )
        return 1;
    for ( long long i = 2 ; i <= (int)sqrt(n) + 1; i++ )
    {
        if ( n % i == 0 )
            return 0;
    }
    return 1;
}

int main()
{
    long long n;
    printf("Please input a number n (1<n<1000000000): ");
    scanf("%lld" , &n);
    printf("%lld = " , n );
    int tmp = 0;
    for ( long long i = 2 ; i <= n ; i++ )
    {
        if ( prime_factorization(i) )
        {
            if ( n % i == 0 )
            {
                if ( tmp == 0 )
                    printf("%lld " , i );
                else
                    printf("* %lld " , i );
                n = n / i;
                i -= 1;
                tmp++;
                if ( n == 1 )
                {
                    printf("\n");
                    break;
                }
            }
        }
    }
}