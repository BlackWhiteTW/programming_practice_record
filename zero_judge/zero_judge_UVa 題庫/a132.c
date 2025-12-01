#include<stdio.h>

int main()
{
    int n;
    while ( scanf( "%d" , &n ) != EOF )
    {
        if ( n == 0 )
            return 0;
        int b[101] = {0} , tmp = n , i , one_count = 0;
        for ( i = 0 ; i < n ; i++ )
        {
            if ( tmp == 0 )
                break;
            if ( tmp % 2 == 1 )
            {
                b[i] = 1;
                one_count++;
            }
            tmp /= 2;
        }
        printf( "The parity of " );
        for( int j = i - 1 ; j >= 0 ; j-- )
            printf( "%d" , b[j] );
        printf( " is %d (mod 2).\n" , one_count );
    }
    
}