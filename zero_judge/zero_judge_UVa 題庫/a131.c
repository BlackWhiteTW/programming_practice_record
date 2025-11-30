#include<stdio.h>

int ret( char c )
{
    if ( c == 'B' || c == 'P' || c == 'F' || c == 'V' )
        return 1;
    if ( c == 'C' || c == 'S' || c == 'K' || c == 'G' || c == 'J' || c == 'Q' || c == 'X' || c == 'Z' )
        return 2;
    if ( c == 'D' || c == 'T' )
        return 3;
    if ( c == 'L' )
        return 4;
    if ( c == 'M' || c == 'N' )
        return 5;
    if ( c == 'R' )
        return 6;
    return 0;
}

int main()
{
    char str[1000];
    printf( "         NAME                     SOUNDEX CODE\n" );
    while ( scanf( "%s" , str ) != EOF )
    {
        printf( "         %-25s%c" , str , str[0] );
        int num[3] = {0}, count = 0 , index = 1;
        if ( ret(str[1]) == ret(str[0]) && ret(str[1]) != 0 )
            index++;
        for ( int i = 1 ; i <= 20 ; i++ )
        {
            if ( ret( str[i] ) == 0 )
            {
                if ( ret( str[index++] ) != 0 )
                {
                    if ( ret( str[index-1] ) != ret( str[index-2] ) )
                        num[count++] = ret( str[index-1] );
                }
                else
                    i--;
                if ( index > 20 || count >= 3 )
                    break;
            }
        }
        printf( "%d%d%d\n" , num[0] , num[1] , num[2] );
        for ( int i = 0 ; i < 1000 ; i++ )
            str[i] = '\0';
    }
    printf( "                   END OF OUTPUT\n" );
    return 0;
}