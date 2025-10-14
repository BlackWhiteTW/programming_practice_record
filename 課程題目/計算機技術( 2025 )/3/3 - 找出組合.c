#include <stdio.h>

int main()
{
    int n;
    long long ans = 0;
    printf("N = ");
    scanf("%d", &n);
    for (int i = 1; i < n / 4; i++)
        for (int j = i + 1; j < n / 3; j++)
        {
            int s = j + 1;
            int e = (n - i - j - 1) / 2;
            if (s <= e)
                ans += e - s + 1;
        }
    printf("Total is %lld.\n", ans);
}