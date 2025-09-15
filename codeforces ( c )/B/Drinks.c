#include <stdio.h>

int main()
{
    int n;
    scanf( "%d" , &n );
    double tmp , ans = 0.0;
    for ( int i = 0 ; i < n ; i++ )
    {
        scanf( "%lf" , &tmp );
        ans += tmp;
    }
    printf( "%.12f\n" , ans / n );
}