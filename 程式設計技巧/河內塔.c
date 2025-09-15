#include <stdio.h>

int tap=0;

void hanoi(int n , char A, char B, char C)
{
    if(n = 1)
    {
        printf("%c -> %c\n", A, C);
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
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    
    printf( "%d\n", tap ); 

    return 0;

}