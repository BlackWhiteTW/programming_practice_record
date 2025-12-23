#include<stdio.h>

int main()
{
    int i = 10;
    int *p = &i;
    printf( "a = %d\n" , *p );
    printf( "b = %d\n" , *&p );
    // printf( "c = %d\n" , *i ); ERROR
    printf( "d = %d\n" , *&i );
    printf( "e = %d\n" , &p );
    printf( "f = %d\n" , &*p );
    printf( "g = %d\n" , &i );
    // printf( "h = %d\n" , &*i ); ERROR
    return 0;
}

/*
a = 10
b = 6422296
d = 10
e = 6422300
f = 6422296
g = 6422296
*/