#include <stdio.h>
#include <math.h>

int perfect_number( int n )
{
    int sum = 1;
    for( int i = 2 ; i <= sqrt(n) ; i++ )
    {
        if ( n % i == 0 )
        {
            sum += i;
            if ( i != n / i )
                sum += n / i;
        }
    }
    return sum ;
}

int main()
{
    int n[100] = {0} , count = 0;
    while ( 1 )
    {
        int in;
        scanf( "%d", &in );
        if ( in == 0 )
            break;
        else
            n[count++] = in;
    }

    printf( "PERFECTION OUTPUT\n" );
    for (int i = 0; i < count; i++)
    {
        int num = perfect_number( n[i] );
        if ( num == n[i] )
            printf( "%5d  PERFECT\n" , n[i] );
        else if ( num < n[i] )
            printf( "%5d  DEFICIENT\n" , n[i] );
        else
            printf( "%5d  ABUNDANT\n" , n[i] );
    }
    printf( "END OF OUTPUT\n" );
}