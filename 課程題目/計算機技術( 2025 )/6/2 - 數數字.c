#include <stdio.h>

int number[10] , i , j;

void numup(int n)
{
    if (n >= 10)
        numup(n / 10);
    for (j = 0; j < 10; j++)
        if (n % 10 == j)
        {
            number[j]++;
            break;
        }
}

int main()
{
    for (i = 0; i < 10; i++)
        number[i] = 0;
    int n1 , n2;
    printf("請輸入 A:B...... ");
    scanf("%d:%d", &n1, &n2);
    printf("從 %d 到 %d 的數字中...... \n", n1, n2);
    for (i = n1; i <= n2; i++)
        numup(i);
    printf("0~9 數字的出現次數為...... ");

    printf("%d", number[0]);
    for (j = 1; j < 10; j++)
        printf(", %d", number[j]);
}