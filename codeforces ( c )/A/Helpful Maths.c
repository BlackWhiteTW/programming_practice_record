#include <stdio.h>

int main()
{
    char s[101] = {0};
    scanf("%s", s);
    int n[50] , tmp = 0;
    for ( int i = 0 ; i < 101 ; i++ )
        if ( s[i] >= '0' && s[i] <= '9' )
            n[tmp++] = s[i] - '0';
    for ( int i = 0 ; i < tmp - 1 ; i++ )
        for ( int j = i + 1 ; j < tmp ; j++ )
            if ( n[i] > n[j] )
            {
                int t = n[i];
                n[i] = n[j];
                n[j] = t;
            }
    for ( int i = 0 ; i < tmp ; i++ )
    {
        if ( i < tmp - 1 )
            printf("%d+", n[i]);
        else
            printf("%d\n", n[i]);
    }
}