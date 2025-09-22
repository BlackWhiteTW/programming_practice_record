#include <stdio.h>

int p(int a , int b)
{
    if (a % b == 0)
        return b;
    else
        return p(b , a % b);
}

int main()
{
    int a , b;
    printf("請輸入長方形的長(公分)為...");
    scanf("%d",&a);
    printf("請輸入長方形的寬(公分)為...");
    scanf("%d",&b);
    int ans1 , ans2;
    ans2 = a * b / p(a , b);
    ans1 = ans2 / p(a , b);
    printf("最少需要 %d 個相同的長方形，排成邊長為 %d 公分的正方形\n", ans1 , ans2);
}