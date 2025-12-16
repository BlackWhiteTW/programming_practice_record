#include<stdio.h>
#include<math.h>

int main()
{
    int n , t = 1 ;
    scanf( "%d" , &n );
    int array[n];
    for ( int i = 0 ; i < n ; i++ )
        scanf( "%d" , &array[i] );
    int num_index = 0 , index = 0 , count = 0 ;
    int a , b;
    while ( count < n )
    {
        count++;
        num_index = 0;
        while ( array[num_index] != count )
            num_index++;

        if ( index > num_index )
            a = index , b = num_index ;
        else
            a = num_index , b = index ;
        for ( int i = b + 1 ; i < a ; i++ )
            if ( array[i] == 0 )
                t--;
        t += abs( index - num_index );
        index = num_index ;
        array[num_index] = 0 ;
    }
    printf( "%d" , t );
}