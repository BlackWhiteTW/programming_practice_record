#include <stdio.h>

int main()
{
    int h , n1 , n2 , n3 , n4 , n5 , n6 , n7;
    float w , m;
    printf("Name : ");
    scanf("%1d%1d%1d%1d%1d%1d%1d" , &n1 , &n2 , &n3 , &n4 , &n5 , &n6 , &n7);
    printf("Height(cm) : ");
    scanf("%d" , &h);
    printf("Weight(kg) : ");
    scanf("%f" , &w);
    float bmi;
    m = h / 100.0;
    bmi = w / ( m * m );
    printf("Name : %d%d%d%d%d%d%d\n", n1 , n2 , n3 , n4 , n5 , n6 , n7);
    printf("BMI = %.2f\n" , bmi);
}