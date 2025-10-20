#include <stdio.h>

int main()
{
    int a , b;
    printf("Please input two integers: ");
    scanf("%d %d" , &a , &b);
    while ( a % b != 0 )
    {
        int temp;
        temp = a % b;
        a = b;
        b = temp;
    }

    printf("GCD is %d\n" , b);
}