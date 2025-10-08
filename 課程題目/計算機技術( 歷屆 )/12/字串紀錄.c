#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fptr;
    char read_file_file[] = "c:\\Users\\91314\\Documents\\彰師 程式設計\\課程題目\\計算機技術( 歷屆 )\\12\\t3.txt";
    char write_file_file[] = "c:\\Users\\91314\\Documents\\彰師 程式設計\\課程題目\\計算機技術( 歷屆 )\\12\\t4.txt";
    char word[100][20] , str[10000] , temp[21];
    int word_count[100] = {0};

    fptr = fopen( read_file_file, "r" );
    while ( fgets( str , 10000 , fptr ) != NULL )
    {
        printf("%s", str);
        for ( int i = 0; str[i] != '\0'; i++ )
        {
            if ( str[i] >= 'A' && str[i] <= 'Z' )
                strncat(temp, &str[i], 1);
            else
            {
                if ( strlen(temp) > 0 )
                {
                    for ( int j = 0 ; j < 100 ; j++ )
                    {
                        if ( strcmp(word[j], temp) == 0 )
                        {
                            word_count[j]++;
                            break;
                        }
                        else if ( word_count[j] == 0 )
                        {
                            strcpy( word[j] , temp );
                            word_count[j] = 1;
                            break;
                        }
                    }
                }
                strcpy(temp, "");
            }
        }
    }
    fclose( fptr );

    fptr = fopen( write_file_file , "w" );
    for ( int i = 0 ; i < 99 ; i++ )
    {
        if ( word_count[i] != 0 )
            fprintf(fptr, "%s: %d", word[i], word_count[i]);
        if ( word_count[i+1] != 0 )
            fprintf(fptr, "\n");
    }
    fclose(fptr);
}