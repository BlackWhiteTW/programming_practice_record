#include <stdio.h>

int main()
{
    int a , b;
    while (1)
    {
        printf("總數量+總腳數:");
        if ( ( scanf("%d%d", &a, &b) != 2 ) || ( a == 0 && b == 0 )  )
            break;
        else if (b % 2 == 1 || a * 2 > b)
        {
            printf("無解\n");
            continue;
        }
        int x = a * 2;
        int y = ( b - x ) / 2;
        x = a - y;
        printf("雞 %d 隻 兔子 %d 隻\n", x, y);
    }
}