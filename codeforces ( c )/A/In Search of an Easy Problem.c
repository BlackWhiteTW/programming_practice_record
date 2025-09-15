#include <stdio.h>

int main()
{
    int n , ans = 0 ;
    scanf( "%d" , &n );
    for ( int i = 0 ; i < n ; i++ )
    {
        int a ;
        scanf( "%d" , &a );
        ans += a;
    }
    if ( ans != 0 )
        printf("HARD\n");
    else
        printf("EASY\n");
}