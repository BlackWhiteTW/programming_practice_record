#include<stdio.h>

int main()
{
    char c = ' ';
    while ( 1 )
    {
        int i = 0 , tmp = 0;
        while ( 1 )
        {
            c = getchar();
            if ( ( c >= 'A' && c <= 'Z' ) || ( c >= 'a' && c <= 'z' ) )
                tmp = 1;

            if ( tmp == 1 && ( c < 'A' || ( c > 'Z' && c < 'a' ) || c > 'z' ) )
            {
                i++;
                tmp = 0;
            }

            if ( c == '\n' )
                break;
            if ( c == EOF )
                return 0;
        }
        printf("%d\n", i);
    }
}