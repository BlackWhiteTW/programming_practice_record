#include <stdio.h>

int main()
{
    char s[101] = {0};
    scanf("%s", s);
    for ( int i = 0 ; s[i] != 0 ; i++ )
    {
        if ( s[i] >= 'A' && s[i] <= 'Z' )
            s[i] = s[i] - 'A' + 'a';
        char t = s[i];
        if ( t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u' || t == 'y' )
            continue;
        printf(".%c", t);
    }
}