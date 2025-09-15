#include <stdio.h>

int main()
{
    int n , m , y = 0 ;
    scanf("%d %d" , &n , &m) ;
    while ( n <= m )
    {
        n *= 3 ;
        m *= 2 ;
        ++y ;
    }
    printf("%d\n" , y) ;
}