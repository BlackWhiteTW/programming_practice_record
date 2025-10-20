#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    FILE *fptr;
    char str[10000];
    char read_file_file[] = "課程題目\\計算機技術( 歷屆 )\\12\\t1.txt";
    char write_file_file[] = "課程題目\\計算機技術( 歷屆 )\\12\\t2.txt";
    int aeiou[5] = {0};

    fptr = fopen( read_file_file , "r" );
    while( fgets( str , 10000 , fptr ) != NULL )
    {
        for ( int i = 0; str[i] != '\0'; i++ ) {
            str[i] = toupper( str[i] );
            if ( str[i] == 'A' )
                aeiou[0]++;
            else if ( str[i] == 'E' )
                aeiou[1]++;
            else if ( str[i] == 'I' )
                aeiou[2]++;
            else if ( str[i] == 'O' )
                aeiou[3]++;
            else if ( str[i] == 'U' )
                aeiou[4]++;
        }
    }
    fclose( fptr );

    fptr = fopen( write_file_file , "w" );
    fprintf( fptr, "A E I O U\n%d %d %d %d %d" , aeiou[0] , aeiou[1] , aeiou[2] , aeiou[3] , aeiou[4] );
    fclose( fptr );
}