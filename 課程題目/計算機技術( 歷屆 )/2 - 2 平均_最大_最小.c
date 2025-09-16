#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    printf("Please input the number of integers:");
    scanf("%d", &n);
    int a[n];
    for ( int i = 0 ; i < n ; i++ )
    {
        printf("Integer #%d:" , i + 1 );
        scanf("%d", &a[i]);
    }
    int sum = 0 , max = a[0], min = a[0];
    for ( int i = 0 ; i < n ; i++ )
    {
        sum += a[i];
        if ( a[i] > max ) max = a[i];
        if ( a[i] < min ) min = a[i];
    }
    printf("the average is %f\n", sum / (float)n);
    printf("the maximum is %d\n", max);
    printf("the minimum is %d\n", min);
    
    system("pause");
    return 0;
}