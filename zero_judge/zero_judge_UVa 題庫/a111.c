#include<stdio.h>

int main()
{
    int a;
    while ( 1 )
    {
        scanf ( "%d" , &a );
        if ( a == 0 )
            break;
        long long int sum = 0;
        for ( int i = 1 ; i <= a ; i++ )
            sum += i * i;
        printf( "%lld\n" , sum );
    }
    return 0;
}