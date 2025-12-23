#include<stdio.h>

int main()
{
    int i = 10;
    int *p = &i;
    int *q = p;
    // p = i; ERROR
    // p = &q; ERROR
    // p = *q; ERROR
    // *p = &i; ERROR
    p = *&q;
    // *p = q; ERROR
    // &p = q; ERROR
    p = q;
    *p = *q;
    return 0;
}