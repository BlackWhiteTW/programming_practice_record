#include <stdio.h>

int main()
{
    int n , a = 0 , b = 0;
    scanf("%d" , &n);
    char str[n + 1];
    scanf("%s" , str);
    for ( int i = 0 ; i < n ; i++ )
    {
        if ( str[i] == 'A' )
            a++;
        else
            b++;
    }
    if ( a > b )
        printf("Anton\n");
    else if ( b > a )
        printf("Danik\n");
    else
        printf("Friendship\n");
}