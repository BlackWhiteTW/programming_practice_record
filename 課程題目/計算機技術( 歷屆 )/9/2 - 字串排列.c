#include <stdio.h>

int sortsort( char str[] )
{
    for ( int i = 0 ; str[i] != '\0' ; i++ )
        for ( int j = i + 1 ; str[j] != '\0' ; j++ )
            if ( str[i] > str[j] )
            {
                char t = str[i];
                str[i] = str[j];
                str[j] = t;
            }
}

int main()
{
    char str[13] = "";
    int ans = 1;
    int c = 1;
    printf("Please input a string:");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
    {
        ans *= i + 1;
    }

    sortsort(str);

    for( int i = 0 ; str[i] != '\0' ; i++ )
    {
        if ( str[i] == str[i+1] )
            c++;
        else
            c = 1;
        ans /= c;
    }
    printf("%d\n", ans);
}