#include <stdio.h>

int main()
{
    int h;
    float w , m;
    char s[8];
    printf("Name : ");
    scanf("%s" , s);
    printf("Height(cm) : ");
    scanf("%d" , &h);
    printf("Weight(kg) : ");
    scanf("%f" , &w);
    float bmi;
    m = h / 100.0;
    bmi = w / ( m * m );
    printf("Name : %s\n", s);
    printf("BMI = %.2f\n" , bmi);
}