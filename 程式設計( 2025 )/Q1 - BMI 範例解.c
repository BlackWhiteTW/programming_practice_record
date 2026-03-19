#include <stdio.h>

int main()
{
    int h , n1 , n2 , n3 , n4 , n5 , n6 , n7;
    float w , m;
    scanf("%1d%1d%1d%1d%1d%1d%1d" , &n1 , &n2 , &n3 , &n4 , &n5 , &n6 , &n7);
    scanf("%d" , &h);
    scanf("%f" , &w);
    float bmi;
    m = h / 100.0;
    bmi = w / ( m * m );
    printf("Student %d%d%d%d%d%d%d's BMI is %.2f!\n", n1 , n2 , n3 , n4 , n5 , n6 , n7, bmi);
}