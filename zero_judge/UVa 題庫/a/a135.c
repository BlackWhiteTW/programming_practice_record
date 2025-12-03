#include<stdio.h>
#include<string.h>

int main()
{
    int t = 1;
    while ( 1 )
    {
        char str[1000] = "" , reply[1000] = "UNKNOWN";
        scanf( "%s" , str );
        if ( str[0] == '#' )
            return 0;

        if ( strcmp( str , "HELLO" ) == 0 )
            strcpy( reply , "ENGLISH" );
        else if ( strcmp( str , "HOLA" ) == 0 )
            strcpy( reply , "SPANISH" );
        else if ( strcmp( str , "HALLO" ) == 0 )
            strcpy( reply , "GERMAN" );
        else if ( strcmp( str , "BONJOUR" ) == 0 )
            strcpy( reply , "FRENCH" );
        else if ( strcmp( str , "CIAO" ) == 0 )
            strcpy( reply , "ITALIAN" );
        else if ( strcmp( str , "ZDRAVSTVUJTE" ) == 0 )
            strcpy( reply , "RUSSIAN" );

        printf( "Case %d: %s\n" , t++ , reply );
    }
}