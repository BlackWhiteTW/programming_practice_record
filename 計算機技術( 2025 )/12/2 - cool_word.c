#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input_text( char *text[] , int size[] )
{
    FILE *fptr;
    int i = 0;
    char str[100] = "";
    char file_name[] = "課程題目\\計算機技術( 2025 )\\12\\t15.txt";
    
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
        for (int j = 0; j < size[i]; j++)
            if ( str[j] >= 'A' && str[j] <= 'Z' )
                str[j] = str[j] + ('a' - 'A');
        strcpy( text[i] , str );
        i++;
    }
    fclose(fptr);
}

void sort( char text[] , int len )
{
    for ( int i = 0 ; i < len - 1 ; i++ )
        for ( int j = i + 1 ; j < len ; j++ )
            if ( text[i] > text[j] )
            {
                char temp = text[i];
                text[i] = text[j];
                text[j] = temp;
            }
}

int main()
{
    char *text[1000] = {NULL}; 
    int size[1000] = {0};
    input_text( text , size );
    for ( int i = 0 ; text[i] != NULL ; i++ )
        sort( text[i] , size[i] );
    for ( int i = 0 ; text[i] != NULL ; i++ )
    {
        int array[26] = {0} , cool_word = 1;
        for ( int j = 0 ; j < size[i] ; j++ )
            array[ text[i][j] - 'a' ]++;
        for ( int j = 0 ; j < 25 ; j++ )
            for ( int k = j + 1 ; k < 26 ; k++ )
                if ( array[j] != 0 && array[k] != 0 && array[j] == array[k] )
                    cool_word = 0;
        int count = 0;
        for ( int j = 0 ; j < 26 ; j++ )
            if ( array[j] != 0 )
                count++;
        if ( count < 2 )
            cool_word = 0;

        if ( cool_word )
            printf( "Yes\n" );
        else
            printf( "No\n" );
    }
    for ( int i = 0 ; text[i] != NULL ; i++ )
        free( text[i] );

    return 0;
}