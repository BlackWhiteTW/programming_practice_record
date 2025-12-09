#include <stdio.h>
#include <string.h>
#include <ctype.h>

// 重設字串
void reset_temp ( char temp[] )
{
    for ( int i = 0 ; i < 20 ; i++ )
        temp[i] = '\0';
}

// 讀取檔案
int read_file ( const char* file , char text[2000][20] )
{
    FILE *ptr = fopen( file , "r" );
    char ch , temp[20] = "" ;
    int i = 0;

    while ( ( ch = fgetc( ptr ) ) != EOF )
    {
        ch = tolower( ch );
        if ( ch == ' ' || ch == ',' || ch == '.' || ch == '\n' || ch == '\r' )
        {
            if ( temp[0] != '\0' )
            {
                strcpy( text[i++] , temp );
                reset_temp( temp );
            }
        }
        else
            strncat( temp , &ch , 1 );
    }
    if ( temp[0] != '\0' )
    {
        strcpy( text[i++] , temp );
        reset_temp( temp );
    }

    fclose( ptr );

    return i ;
}

int main()
{
    char r1_text[2000][20] , r2_text[2000][20];
    int r1_size = read_file( "課程題目\\計算機技術( 2025 )\\11\\t10.txt" , r1_text );
    int r2_size = read_file( "課程題目\\計算機技術( 2025 )\\11\\t11.txt" , r2_text );
    int f1_file_text[2000] = { 0 } , repeated_words = 0;

    printf( "文章一共有 %d 個字詞\n" , r1_size );
    printf( "文章二共有 %d 個字詞\n" , r2_size );

    // 比對文章
    for ( int i = 0 ; i < r1_size ; i++ )
    {
        int len = 0 ;
        for ( int j = 0 ; j < r2_size ; j++ )
        {
            if ( strcmp( r1_text[i] , r2_text[j] ) == 0 )
                while ( i + len < r1_size && j + len < r2_size && strcmp( r1_text[i + len] , r2_text[j + len] ) == 0 )
                    len++ ;
            if ( len > 6 )
            {
                for ( int k = 0 ; k < len ; k++ )
                    if ( f1_file_text[i + k] == 0 )
                    {
                        f1_file_text[i + k] = 1;
                        repeated_words++;
                    }
                i += len - 1;
                break;
            }
        }
    }

    printf( "%d / %d = %.2f\n" , repeated_words , r1_size , repeated_words * 100.0 / r1_size  );
}