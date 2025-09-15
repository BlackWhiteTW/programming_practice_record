#include <stdio.h>

int main()
{
    char s1[100], s2[100];
    scanf( "%s %s" , s1 , s2 );
    for ( int i = 0 ; s1[i] ; i++ )
        if ( s1[i] >= 'A' && s1[i] <= 'Z' )
            s1[i] = s1[i] - 'A' + 'a';
    for ( int i = 0 ; s2[i] ; i++ )
        if ( s2[i] >= 'A' && s2[i] <= 'Z' )
            s2[i] = s2[i] - 'A' + 'a';
    int res = 0;
    for ( int i = 0 ; s1[i] && s2[i] ; i++ )
    {
        if ( s1[i] < s2[i] )
        {
            res = -1;
            break;
        }
        else if ( s1[i] > s2[i] )
        {
            res = 1;
            break;
        }
    }
    printf("%d\n", res);
}