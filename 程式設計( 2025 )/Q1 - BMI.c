#include <stdio.h>

int main()
{
    int h;
    float w , m;
    char s[8];
    scanf("%s" , s);
    scanf("%d" , &h);
    scanf("%f" , &w);
    float bmi;
    m = h / 100.0;
    bmi = w / ( m * m );
    printf("Student %s's BMI is %.2f!\n", s, bmi);
}