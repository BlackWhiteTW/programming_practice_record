#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_repeat( char str[][20] , char in_str[] , int count[] )
{
    for ( int i = 0 ; i < 100 ; i++ )
    {
        if ( strcmp( str[i] , in_str ) == 0 )
        {
            count[i]++;
            return;
        }
        else if ( strlen( str[i] ) == 0 )
        {
            strcpy( str[i] , in_str );
            count[i] = 1;
            return;
        }
    }
}

int main()
{
    FILE *fptr;
    char read_file_file[] = "課程題目\\計算機技術( 2025 )\\10\\t3.txt";
    char write_file_file[] = "課程題目\\計算機技術( 2025 )\\10\\t4.txt";
    char word[100][20] , c , temp[21];
    int word_count[100] = {0};

    fptr = fopen( read_file_file, "r" );
    while ( (c = fgetc( fptr ) ) != EOF )
    {
        if ( c != '.' && c != ',' && c != '!' && c != '?' && c != ' ' && c != '\n' )
            strncat(temp, &c, 1);
        else
        {
            if ( strlen( temp ) > 0 )
                str_repeat( word , temp , word_count );
            strcpy(temp, "");
        }
    }
    fclose( fptr );

    fptr = fopen( write_file_file , "w" );
    for ( int i = 0 ; i < 99 ; i++ )
    {
        if ( word_count[i] != 0 )
            fprintf(fptr, "%s: %d\n", word[i], word_count[i]);
    }
    fclose(fptr);
}