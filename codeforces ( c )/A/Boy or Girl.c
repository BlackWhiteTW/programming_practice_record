#include <stdio.h>

int main()
{
    char s[101] = {0};
    scanf("%s", s);
    bool alpha[26] = {false};
    for ( int i = 0 ; s[i] != 0 ; i++ )
        alpha[s[i]-'a'] = true;
    int count = 0;
    for ( int i = 0 ; i < 26 ; i++ )
        if ( alpha[i] )
            count++;
    if ( count % 2 == 0 )
        printf("CHAT WITH HER!\n");
    else
        printf("IGNORE HIM!\n");
}