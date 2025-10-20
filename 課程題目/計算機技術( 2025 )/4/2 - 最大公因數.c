#include <stdio.h>

int main()
{
    int a , b;
    printf("Please input two integers: ");
    scanf("%d %d" , &a , &b);
    while ( a % b != 0)
    {
        a %= b;
        b += a;
        a = b - a;
        b -= a;
    }
    printf("GCD is %d\n" , b );
}