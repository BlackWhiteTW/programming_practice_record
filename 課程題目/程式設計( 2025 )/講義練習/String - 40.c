#include<stdio.h>
#include<string.h>

int main( int argc , char *argv[] )
{
    char *planets[] = { "Mercury" , "Venus" , "Earth" ,
                        "Mars" , "Jupiter" , "Saturn" ,
                        "Uranus" , "Neptune" , "Pluto" };
    printf( "argc = %d\n" , argc );
    for ( int i = 0 ; i < argc ; i++ )
    {
        int if_printed = 0;
        printf( "argv[%d] = %s\n" , i , argv[i] );
        for ( int j = 0 ; j < 9 ; j++ )
            if ( strcmp( argv[i] , planets[j] ) == 0 )
            {
                printf( "  %s is planet %d\n" , argv[i] , j + 1 );
                if_printed = 1;
            }
        if ( !if_printed )
            printf( "  %s is not a planet\n" , argv[i] );
    }
    return 0;
}