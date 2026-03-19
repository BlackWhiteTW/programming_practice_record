#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input_text( char *text[] , int size[] )
{
    FILE *fptr;
    int i = 0;
    char str[100] = "";
    char file_name[] = "課程題目\\計算機技術( 2025 )\\12\\t12.txt";
    
    fptr = fopen( file_name , "r" );
    
    if (fptr == NULL)
    {
        printf("無法開啟檔案: %s\n", file_name);
        return;
    }

    while ( fscanf( fptr, "%s" , str ) != EOF )
    {
        size[ i ] = strlen( str );
        text[i] = ( char* )calloc( size[i] + 1, sizeof( char ) );
        strcpy( text[i] , str );
        i++;
    }
    fclose(fptr);
}

int main()
{
    char *text[1000] = {NULL}; 
    int size[1000] = {0};
    input_text( text , size );

    if (text[0] == NULL) 
        return 0;

    int line_len = 0;
    printf( "The width of word wrap:" );
    scanf( "%d" , &line_len );

    int len = line_len;
    for ( int i = 0 ; text[i] != NULL ; i++ )
    {
        int a = 0;
        if ( len == -1 )
        {
            printf( "\n " );
            len = line_len - 1;
            a = 1;
        }
        if ( size[i] <= len )
        {
            printf( "%s " , text[i] );
            len -= ( size[i] + 1 );
        }
        else if( size[i] > len && size[i] <= line_len )
        {
            printf( "\n%s " , text[i] );
            len = line_len - ( size[i] + 1 );
        }
        else
        {
            int start = 0;
            if ( !a )
            {
                printf( "\n" );
                len = line_len;
            }
            while( size[i] - start > line_len )
            {
                for ( int j = start ; j < start + line_len - a ; j++ )
                    printf( "%c" , text[i][j] );
                printf( "\n" );
                start += line_len - a;
                a = 0;
            }
            printf( "%s " , &text[i][start] );
            len = line_len - ( size[i] - start + 1 );
        }
    }
    printf( "\n" );
    
    return 0;
}