#include <stdio.h>

int prime(long long a , long long b)
{
    a %= b;
    if ( a == 0 )
        return b;
    else
        return prime(b , a);
}

int main()
{
    int a , b;
    printf("Please input two integers: ");
    scanf("%d %d" , &a , &b);
    printf("GCD is %d\n" , prime(a , b) );
}