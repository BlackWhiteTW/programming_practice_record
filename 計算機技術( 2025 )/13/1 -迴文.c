#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_palindrome ( char str[] , int start , int end )
{
    int tmp = 0 , time = 0;
    for ( int i = start ; i <= (start + end) / 2 ; i++ , time++)
        if ( str[i] != str[end - time] )
            return 0;
    return 1;
}

void palindorme_return ( char str[] , int start , int end , char palindrome[][9] , int *pal_len )
{
    char temp[9] = "";
    strncpy( temp , &str[start] , end - start + 1 );
    for ( int i = 0 ; i < (*pal_len) ; i++ )
        if ( strcmp( palindrome[i] , temp ) == 0 )
            return ;
    strcpy( palindrome[*pal_len] , temp );
    (*pal_len)++;
}

int main()
{
    char str[101] = "";
    printf("請輸入一個字串 : ");
    scanf("%s", str);
    int slen = 0 , max_len = 1 , max_len_tmp = 0 ;
    slen = strlen(str);
    char palindrome[100][9] = {0};

    for ( int i = 0 ; i < slen ; i++ )
    {
        for ( int j = i ; j < slen ; j++ )
        {
            if ( is_palindrome( str , i , j ) )
            {
                if ( j - i + 1 > max_len )
                {
                    max_len_tmp = 0;
                    max_len = j - i + 1;
                    palindorme_return( str , i , j , palindrome , &max_len_tmp );
                }
                if ( j - i + 1 == max_len )
                    palindorme_return( str , i , j , palindrome , &max_len_tmp );
            }
        }
    }

    printf("最長迴文為 : ");
    for ( int i = 0 ; i < max_len_tmp ; i++ )
    {
        printf( "%s" , palindrome[i] );
        if ( i < max_len_tmp - 1)
            printf(", ");
    }
}
