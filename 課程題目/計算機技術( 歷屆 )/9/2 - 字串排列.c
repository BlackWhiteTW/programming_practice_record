#include <stdio.h>

int main()
{
    char str[13] = "";
    printf("Please input a string:");
    scanf("%s", str);

    long long int ans = 1;
    for (int i = 1; str[i] != '\0'; i++)
    {
        ans *= i;
    }
    printf("%lld\n", ans);

    sort(str);
}