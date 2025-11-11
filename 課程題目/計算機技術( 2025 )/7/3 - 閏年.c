#include <stdio.h>

int main()
{
    long long int year1, year2, m1, m2, d1, d2, ans = 0, year_d;
    printf("請輸入西元開始日期(yyyy/mm/dd)為...");
    scanf("%lld/%lld/%lld", &year1, &m1, &d1);
    printf("請輸入西元結束日期(yyyy/mm/dd)為...");
    scanf("%lld/%lld/%lld", &year2, &m2, &d2);
    if ( year1 % 4 == 0 && year1 % 100 != 0 || year1 % 400 == 0 )
        if ( m1 <= 2 )
            ans++;
    if ( year2 % 4 == 0 && year2 % 100 != 0 || year2 % 400 == 0 )
        if ( m2 < 3 || ( m2 == 2 && d2 != 29 ) )
            ans--;

    year_d = year2 - year1;

    ans += (year_d / 4) - (year_d / 100) + (year_d / 400);

    printf("此時間的 2 月 29 日 共有 %lld 次\n", ans);
}