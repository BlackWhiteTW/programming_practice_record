#include<stdio.h>

int gcd( int a , int b )
{
    if ( b == 0 )
        return a;

    if ( a < b )
        return gcd( b , a );

    return gcd( b , a % b );
}

int main()
{
    int n;
    scanf( "%d" , &n );
    getchar();
    for ( int i = 0 ; i < n ; i++ )
    {
        int array[1000] = {0} , count = 0 , temp = 0 , max_gcd = 0;
        char c;
        while ( ( c = getchar() ) != EOF )
        {
            if ( c == ' ' || c == '\n' )
            {
                array[count++] = temp;
                temp = 0;
            }
            else
                temp = temp * 10 + ( c - '0' );

            if ( c == '\n' )
                break;
        }

        for ( int j = 0 ; j < count - 1 ; j++ )
            for ( int k = j + 1 ; k < count ; k++ )
                if ( gcd( array[j] , array[k] ) > max_gcd && array[j] != 0 && array[k] != 0 )
                    max_gcd = gcd( array[j] , array[k] );

        printf( "%d\n" , max_gcd );
    }
    return 0;
}