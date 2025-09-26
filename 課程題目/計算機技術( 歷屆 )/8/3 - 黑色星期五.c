#include <stdio.h>

int main()
{
    int c , ans = 0;
    printf("Please input the century: ");
    scanf("%d", &c);

    int w , y = ( c - 1 ) * 100 + 1;
    int m[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

    for ( int i = y ; i < y + 100 ; i++ )
    {
        w = i + ( i - 1 ) / 4 - ( i - 1 ) / 100 + ( i - 1 ) / 400 + 12 ;
        w %= 7;
        if ( ( i % 4 == 0 && i % 100 != 0 ) || ( i % 400 == 0 ) )
            m[1] = 29;
        else
            m[1] = 28;
        for ( int j = 0 ; j < 12 ; j++ )
        {
            w = ( w + m[j] ) % 7;
            if ( w == 5 )
                ans++;
        }
    }

    printf("%d times!!\n", ans);
}