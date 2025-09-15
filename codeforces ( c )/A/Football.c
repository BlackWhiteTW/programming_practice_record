#include <stdio.h>

int main()
{
    char s[101] = {5};
    scanf( "%s" , s );
    int t = 0; 
    for (int i = 0 ; s[i] != '\0' ; i++)
    {
        if ( s[i] == s[i+1] )
            t++;
        else
            t = 0;
        if ( t == 6 )
        {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}