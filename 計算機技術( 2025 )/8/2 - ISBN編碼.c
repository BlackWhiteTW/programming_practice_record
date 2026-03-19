#include <stdio.h>
#include <string.h>

int check_ISBN10 ( char *arr )
{
    int sum = 0;
    for ( int i = 0 ; i < 10 ; i++ )
    {
        if ( arr[i] == 'X' )
            sum += 10;
        else
            sum += ( arr[i] - '0' ) * (10 - i);
    }
    if ( sum % 11 == 0 )
        return 1;
    else
        return 0;
}

int check_ISBN13 ( char *arr )
{
    int sum = 0;
    for ( int i = 0 ; i < 13 ; i++ )
    {
        if ( i % 2 == 0 )
            sum += ( arr[i] - '0' );
        else
            sum += ( arr[i] - '0' ) * 3;
    }
    if ( sum % 10 == 0 )
        return 1;
    else
        return 0;
}

int main()
{
    while ( 1 )
    {
        int result;
        char arr[14] = "";
        printf("Please input an ISBN code: ");
        scanf("%s", arr);
        if ( strlen(arr) == 10 )
            result = check_ISBN10( arr );
        else if ( strlen(arr) == 13 )
            result = check_ISBN13( arr );
        else
        {
            printf("Error!\n");
            return 0;
        }
        if ( result )
            printf("The ISBN code is correct!!\n");
        else
            printf("The ISBN code is wrong!!\n");
    }
}