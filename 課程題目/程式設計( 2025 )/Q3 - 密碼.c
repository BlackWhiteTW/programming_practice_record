#include <stdio.h>
#include <string.h>

int main()
{
    int m = 1;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        char ans[5] = "";
        scanf("%s", ans);
        while ( 1 )
        {
            char instr[100] = "";
            scanf("%s", instr);
            int a = 0 , b = 0 ;
            if ( strlen(instr) != 4 || instr[0] == '-' )
                printf("Invalid input!\n");
            else
            {
                for ( int j = 0 ; j < 4 ; j++ )
                {
                    if ( instr[j] == ans[j] )
                            a++;
                    else
                        for ( int k = 0 ; k < 4 ; k++ )
                            if ( instr[j] == ans[k] )
                                b++;
                } 
                if ( a == 4 )
                {
                    printf("Success!!\n");
                    break;
                }
                else
                    printf("%dA%dB\n", a, b);
            }
        }
    }
}