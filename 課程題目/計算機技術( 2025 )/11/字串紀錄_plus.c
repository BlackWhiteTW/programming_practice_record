#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// 將讀到的字串做判斷與處理 檢查是否已儲存過 沒就添加 有就增加次數
void process_word(char temp[21], char word[100][20], int word_count[100])
{
    if ( strlen(temp) > 0 )
        for ( int j = 0 ; j < 100 ; j++ )
        {
            if ( strcmp( word[j] , temp ) == 0 )
            {
                word_count[j]++;
                return;
            }
            if ( word[j][0] == '\0' )
            { 
                strcpy( word[j] , temp );
                word_count[j] = 1;
                return;
            }
        }
}

int main()
{
    FILE *fptr;
    char read_file_file[] = "課程題目\\計算機技術( 2025 )\\11\\t5.txt";
    char write_file_file[] = "課程題目\\計算機技術( 2025 )\\11\\t6.txt";
    char word[100][20] , str[10000] , temp[21];
    int word_count[100] = {0} , t = 0 , word_idx = 0;
    for( int i=0 ; i < 100 ; i++ )
        word[i][0] = '\0';

    fptr = fopen( read_file_file , "r" );
    while( fgets( str , 10000 , fptr ) != NULL )
    {
        for ( int i = 0 ; str[i] != '\0' ; i++ )
        {
            str[i] = tolower( str[i] );
            if ( str[i] == ' ' || str[i] == ',' || str[i] == '.' || str[i] == '\n' || str[i] == '\r' )
            {
                process_word( temp , word , word_count );
                temp[0] = '\0';
            }
            else
                strncat( temp , &str[i], 1);
        }
        process_word( temp , word , word_count );
    }
    fclose( fptr );

    while( word_idx < 100 && word[word_idx][0] != '\0' )
        word_idx++;

    for ( int i = 0 ; i < word_idx - 1 ; i++ )
        for ( int j = 0 ; j < word_idx - i - 1 ; j++ )
            if ( strcmp( word[j] , word[j + 1] ) > 0 )
            {
                char temp_word[21];
                strcpy( temp_word , word[j] );
                strcpy( word[j] , word[j + 1] );
                strcpy( word[j + 1] , temp_word );

                word_count[j] += word_count[j + 1]; 
                word_count[j + 1] = word_count[j] - word_count[j + 1];
                word_count[j] -= word_count[j + 1];
            }

    fptr = fopen( write_file_file , "w" );
    for ( int i = 0 ; i < word_idx ; i++ )
        fprintf( fptr , "%s: %d\n" , word[i] , word_count[i] );
    fclose( fptr );
}