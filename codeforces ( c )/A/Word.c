#include <stdio.h>

int main()
{
    char s[101] = {0};
    scanf("%s", s);
    int u = 0, l = 0;
    for (int i = 0; s[i]; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            u++;
        else if (s[i] >= 'a' && s[i] <= 'z')
            l++;
    }
    for (int i = 0 ; s[i] != '\0' ; i++)
    {
        if ( u > l )
        {
            if ( s[i] >= 'a' && s[i] <= 'z' )
                s[i] = s[i] - 'a' + 'A';
        }
        else
        {
            if ( s[i] >= 'A' && s[i] <= 'Z' )
                s[i] = s[i] - 'A' + 'a';
        }
    }
    printf("%s\n", s);
}