#include <stdio.h>

int gcd(int a, int b)
{
    while (b)
    {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void sort_fraction(int (*ptr)[2], int n)
{
    for (int i = 0; i <= n - 1; ++i)
        for (int j = i + 1; j < n; ++j)
            if ( (long long)ptr[i][0] * ptr[j][1] > (long long)ptr[j][0] * ptr[i][1] )
            {
                int tn = ptr[i][0], td = ptr[i][1];
                ptr[i][0] = ptr[j][0];
                ptr[i][1] = ptr[j][1];
                ptr[j][0] = tn;
                ptr[j][1] = td;
            }
}

int main()
{
    int n , m = 0 , all = 0;
    printf("Please input a number: ");
    if (scanf("%d", &n) != 1 || n < 1) return 0;

    int num[ n * (n + 1) / 2 ][2];

    // 0/1
    num[m][0] = 0;
    num[m][1] = 1;
    m++;
    // 1/1
    num[m][0] = 1;
    num[m][1] = 1;
    m++;

    for (int b = 1; b <= n; ++b) {
        for (int a = 1; a <= b; ++a) {
            int g = gcd(a, b);
            int na = a / g, nb = b / g;
            int dup = 0;
            num[m][0] = na;
            num[m][1] = nb;
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