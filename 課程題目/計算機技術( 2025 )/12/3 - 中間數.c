#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input_text( int number[] )
{
    FILE *fptr;
    int i = 0;
    char str[100] = "";
    char file_name[] = "課程題目\\計算機技術( 2025 )\\12\\t16.txt";
    
    fptr = fopen( file_name , "r" );
    
    if (fptr == NULL)
    {
        printf("無法開啟檔案: %s\n", file_name);
        return;
    }

    while ( fscanf( fptr, "%s" , str ) != EOF )
    {
        int temp = 0;
        for( int j = 0 ; str[j] != '\0' ; j++ )
            temp = temp * 10 + ( str[j] - '0' );
        number[i] = temp;
        i++;
    }
    fclose(fptr);
}

int main()
{
    int number[1000] = {0};
    input_text( number );
    for( int i = 0 ; number[i] != 0 ; i++ )
    {
        int min = 0 , max = number[i] , index = number[i] / 2 ;
        while ( 1 )
        {
            min = ( 1 + index ) * index / 2;
            max = ( index + number[i] ) * ( number[i] - index + 1 ) / 2;
            if ( min == max )
            {
                printf( "%-10d %d\n" , number[i] , index );
                break;
            }
            if ( index >= number[i] )
            {
                printf( "%-10d Null\n" , number[i] );
                break;
            }
            index++;
        }
    }
}