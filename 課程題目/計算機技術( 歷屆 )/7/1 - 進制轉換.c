#include <stdio.h>
#include <stdbool.h>

int main(){
    int n;
    bool binary[32] = {0} , tmp = false;
    printf("Please input a decimal number: ");
    scanf("%d", &n);
    for (int i = 0; i < 32; i++)
    {
        binary[i] = n % 2;
        n /= 2;
    }
    for (int i = 31; i >= 0; i--)
    {
        if (binary[i])
            tmp = true;
        if (tmp)
            printf("%d", binary[i]);
    }
    printf("\n");

    printf("Please input a binary number: ");
    char s[33];
    scanf("%s", s);
    n = 0;
    for (int i = 0; s[i]; i++)
        n = n * 2 + (s[i] - '0');
    printf("%d\n", n);
}