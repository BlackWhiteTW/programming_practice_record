#include <stdio.h>
#include <math.h>

int ipow( int a , int b )
{
    int ans = 1;
    for ( int i = 0 ; i < b ; i++)
        ans *= a;
    return ans;
}
int main()
{
    int n , ans = 0;
    printf("Please input a number: ");
    scanf("%d" , &n);
    for ( int i = 0 ; i <= n ; i++ )
    {
        int a = 1 , tmp = i;
        while ( tmp >= 10)
        {
            tmp /= 10;
            a ++;
        }
        int anstmp = 0;
        tmp = i;
        for ( int j = 0 ; j < a ; j++)
        {
            tmp %= ipow( 10 , j + 1 );
            tmp /= ipow( 10 , j );
            anstmp += ipow( tmp , a );
            tmp = i;
        }
        if ( anstmp > n )
            continue;
        if ( anstmp == i )
        {
            if ( ans == 0 )
                printf("%d" , anstmp);
            else
                printf(", %d", anstmp);
            ans++;
        }
    }
    printf("\nTotal %d\n" , ans);
}