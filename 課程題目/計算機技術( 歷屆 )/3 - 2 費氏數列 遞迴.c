#include <stdio.h>
#include <stdlib.h>

int n = 0;

void fes(int a , int b , int c)
{
    if ( a > n ) 
        return;
    if ( a == n )
        printf("%d\n", c);
    else
        printf("%d, ", c);
    if ( c == 0 )
        fes(a + 1 , b , 1);
    else
        fes(a + 1 , c , b + c);
}

int main()
{
    printf("Please input a number:");
    scanf("%d", &n);
    fes(1 , 0 , 0);
    
    system("pause");
    return 0;
}