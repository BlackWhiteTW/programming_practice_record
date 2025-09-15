#include <stdio.h>

long long lucky(long long n)
{
    long long cnt = 0;
    while (n)
    {
        if (n % 10 == 4 || n % 10 == 7)
            cnt++;
        n /= 10;
    }
    return (cnt == 4 || cnt == 7);
}

int main()
{
    long long n;
    scanf("%lld", &n);
    if (lucky(n))
        printf("YES\n");
    else
        printf("NO\n");
    return 0;
}