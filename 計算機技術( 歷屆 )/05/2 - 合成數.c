#include <stdio.h>
#include <stdbool.h>

static bool is_prime(int x) {
    x = sqrt(x) + 1;
    if (x < 2)
        return false;
    if (x % 2 == 0)
        return x == 2;
    for (int d = 3; d * d <= x; d += 2)
        if (x % d == 0)
            return false;
    return true;
}

int main()
{
    int n , ans = 0 , prev = 23;
    printf("Please input a number: ");
    scanf("%d", &n);
    if (n < 23) {
        printf("Total=0\n");
        return 0;
    }
    for (int a = prev + 1; a <= n; ++a)
    {
        if (!is_prime(a))
            continue;
        if (a - prev > 4)
        {
            for (int j = prev + 1; j <= a - 4; ++j)
            {
                printf("(%d,%d,%d,%d) ", j, j + 1, j + 2, j + 3);
            }
            ans += a - prev - 4;
        }
        prev = a;
    }
    printf("\nTotal=%d\n", ans);
}