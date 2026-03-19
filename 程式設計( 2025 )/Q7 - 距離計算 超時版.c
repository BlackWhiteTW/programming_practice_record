#include <stdio.h>

int main()
{
    int n;
    scanf( "%d" , &n );
    for ( int i = 1 ; i <= n ; i++ )
    {
        int x1 , y1 , x2 , y2;
        scanf( "%d %d %d %d" , &x1 , &y1 , &x2 , &y2 );
        int tmp = x1 + y1 , t = 0;
        while ( 1 )
        {
            if ( y1 == 0 && ( x1 != x2 || y1 != y2 ) )
            {
                tmp++;
                y1 = tmp;
                x1 = 0;
                t++;
            }
            if ( x1 != x2 || y1 != y2 )
            {
                x1++;
                y1--;
                t++;
            }
            if ( x1 == x2 && y1 == y2 )
                break;
        }
        printf( "Case %d : %d\n" , i , t );
    }
}