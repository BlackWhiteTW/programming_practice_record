#include <stdio.h>

int tap=0;

void hanoi(int n , char A, char B, char C)
{
    if(n == 1)
    {
        printf("ring %d: %c => %c\n", tap, A, C);
        tap++;
    }
    else
    {
        hanoi(n-1, A, C, B);
        hanoi(1, A, B, C);
        hanoi(n-1, B, A, C);
    }
}

int main()
{
    int n;
    printf("請輸入A柱中的環個數:\n");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');

    printf("共需 %d 個步驟\n", tap);

    return 0;

}