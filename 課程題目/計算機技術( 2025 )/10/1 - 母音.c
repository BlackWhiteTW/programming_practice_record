#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *fptr;
    char c;
    char read_file_file[] = "課程題目\\計算機技術( 2025 )\\10\\t1.txt";
    char write_file_file[] = "課程題目\\計算機技術( 2025 )\\10\\t2.txt";
    int aeiou[5] = {0};

    fptr = fopen( read_file_file , "r" );
    while( (c = fgetc( fptr ) ) != EOF )
    {
        c = toupper( c );
        if ( c == 'A' )
            aeiou[0]++;
        else if ( c == 'E' )
            aeiou[1]++;
        else if ( c == 'I' )
            aeiou[2]++;
        else if ( c == 'O' )
            aeiou[3]++;
        else if ( c == 'U' )
            aeiou[4]++;
    }
    fclose( fptr );

    fptr = fopen( write_file_file , "w" );
    fprintf( fptr , "A E I O U\n%d %d %d %d %d" , aeiou[0] , aeiou[1] , aeiou[2] , aeiou[3] , aeiou[4] );
    fclose( fptr );
}