#include<stdio.h>

int main()
{
    int n = 0;
    char ch;
    while ( ( ch = getchar() ) != EOF )
    {
        if ( ch == '"')
        {
            if ( n % 2 == 0 )
                printf( "``" );
            else
                printf( "''" );
            n++;
        }
        else
            putchar( ch );
    }
}