#include <stdio.h>

int main()
{
    int m = 1;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        int ans[4] = {0};
        scanf("%1d%1d%1d%1d", &ans[0], &ans[1], &ans[2], &ans[3]);
        while ( 1 )
        {
            int inint = 0 , a = 0 , b = 0 , idx = 0 , instr[4] = {0};
            scanf("%d", &inint);
            if ( inint < 1000 || inint > 9999 )
                printf("ERROR\n");
            else
            {
                for ( int temp = inint ; temp > 0 ; temp /= 10 , idx++ )
                    instr[3 - idx] = temp % 10;
                for ( int j = 0 ; j < 4 ; j++ )
                {
                    if ( instr[j] == ans[j] )
                        a++;
                    else
                        for ( int n = 0 ; n < 4 ; n++ )
                            if ( instr[j] == ans[n] )
                                b++;
                }
                if ( a == 4 )
                {
                    printf("正確\n");
                    break;
                }
                else
                    printf("%dA%dB\n", a, b);
            }
        }
    }
}