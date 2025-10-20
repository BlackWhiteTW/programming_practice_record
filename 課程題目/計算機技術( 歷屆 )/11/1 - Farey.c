#include <stdio.h>

void swap( int *a, int *b )
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int gcd( int a, int b )
{
    while (b)
    {
        a %= b;
        swap(&a, &b);
    }
    return a;
}

void sort_fraction(int (*ptr)[2], int n)
{
    for (int i = 0; i <= n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if ( (long long)ptr[i][0] * ptr[j][1] > (long long)ptr[j][0] * ptr[i][1] )
            {
                swap(&ptr[i][0], &ptr[j][0]);
                swap(&ptr[i][1], &ptr[j][1]);
            }
}

int main()
{
    int n , m = 0 , all = 0;
    printf( "Please input a number: " );
    if ( scanf( "%d" , &n ) != 1 || n < 1 )
        return 0;
    int num[ n * (n + 1) / 2 ][2];

    num[m][0] = 0;
    num[m][1] = 1;
    num[m][0] = 1;
    num[m][1] = 1;
    m += 2;

    for ( int b = 1 ; b <= n ; ++b )
    {
        for ( int a = 1 ; a <= b ; ++a )
        {
            int g = gcd( a, b );
            num[m][0] = a / g;
            num[m][1] = b / g;
            m++;
        }
    }

    sort_fraction(num, m);

    for (int i = 0; i < m; ++i)
        if (i == 0 || num[i][0] != num[i - 1][0] || num[i][1] != num[i - 1][1])
        {
            if ( num[i][1] == 1 )
                printf("%d", num[i][0]);
            else
                printf("%d/%d", num[i][0], num[i][1]);
            if ( num[i][0] != 1 || num[i][1] != 1 )
                printf(", ");
            all++;
        }

    printf(" (total number: %d)\n", all);
}