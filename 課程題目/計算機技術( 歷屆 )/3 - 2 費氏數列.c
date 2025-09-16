#include <stdio.h>
#include <stdlib.h>

int n = 0;

void array(int a , int b , int c)
{
    if ( a > n ) 
        return;
    printf("%d, ", c);
    if ( c == 0 )
        array(a + 1 , b , 1);
    else
        array(a + 1 , c , b + c);
}
int main()
{
    printf("Please input a number:");
    scanf("%d", &n);
    array(1 , 0 , 0);
    
    system("pause");
    return 0;
}