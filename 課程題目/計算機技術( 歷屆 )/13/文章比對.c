#include <stdio.h>
#include <string.h>
#include <ctype.h>

int read_in_file ( const char* file , char text[2000][20] )
{
    FILE *ptr = fopen( file , "r" );
    char temp[20] = "" , ch ;
    int i = 0 ;

    while ( ( ch = fgetc( ptr ) ) != EOF )
    {
        ch = tolower( ch );
        if ( ch == ' ' || ch == '\n' || ch == '\r' || ch == ',' || ch == '.' || ch == '!' || ch == '?' )
            if ( temp[0] != '\0' )
            {
                strcpy( text[i] , temp );
                i++;
                temp[0] = '\0';
            }
        else
            strncat( temp , &ch , 1 );
    }
    if ( temp[0] != '\0' )
    {
        strcpy( text[i] , temp );
        i++;
    }

    fclose( ptr );

    return i ;
}

int main()
{
    char r1_text[2000][20] , r2_text[2000][20];
    int r1_size = read_in_file( "課程題目\\計算機技術( 歷屆 )\\13\\t10.txt" , r1_text );
    int r2_size = read_in_file( "課程題目\\計算機技術( 歷屆 )\\13\\t11.txt" , r2_text );
    int file_text[2000] = { 0 } , repeated_words = 0;

    for ( int i = 0 ; i < r1_size ; i++ )
    {
        int len = 0 ;
        for ( int j = 0 ; j < r2_size ; j++ )
        {
            if ( strcmp( r1_text[i] , r2_text[j] ) == 0 )
                while ( i + len < r1_size && j + len < r2_size && strcmp( r1_text[i + len] , r2_text[j + len] ) == 0 )
                    len++ ;
            if ( len > 6 )
                for ( int k = 0 ; k < len ; k++ )
                    if ( file_text[i + k] == 0 )
                    {
                        file_text[i + k] = 1;
                        repeated_words++;
                    }
        }
    }

    printf( "%d / %d = %.2f%%\n" , repeated_words , r1_size , repeated_words * 100.0 / r1_size  );
}