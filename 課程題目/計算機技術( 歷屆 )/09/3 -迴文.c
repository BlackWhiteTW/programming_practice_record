#include <stdio.h>
#include <string.h>

int is_palindrome ( char str[] , int start , int end )
{
    int tmp = 0 , time = 0;
    if ( start + end % 2 != 0 )
        tmp = 1;
    for ( int i = start ; i <= (start + end) / 2 ; i++ )
    {
        time++;
        if ( str[i] != str[end + tmp - time] )
            return 0;
    }
    return 1;
}

int main()
{
    char str[101] = "";
    printf("請輸入一個字串 : ");
    scanf("%s", str);
    int slen = 0 , len[100] = {0} , max_len = 1 , max_len_tmp = 0 , printf_time = 0;
    slen = strlen(str);

    for ( int i = 0 ; i < slen ; i++ )
    {
        for ( int j = i ; j < slen ; j++ )
        {
            if ( is_palindrome( str , i , j ) )
            {
                len[i] = j;
                if ( j - i + 1 > max_len )
                {
                    max_len_tmp = 0;
                    max_len = j - i + 1;
                }
                if ( j - i + 1 == max_len )
                    max_len_tmp++;
            }
        }
    }

    printf("最長迴文為 : ");
    for ( int i = 0 ; i < slen ; i++ )
    {
        if ( len[i] - i + 1 == max_len )
        {
            for ( int j = i ; j <= len[i] ; j++ )
                printf("%c", str[j]);
            if ( printf_time < max_len_tmp - 1)
                printf(", ");
            printf_time++;
        }
    }
}
