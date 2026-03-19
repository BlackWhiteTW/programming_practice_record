#include <stdio.h>

int main()
{
    int a , b ;
    char c , s[11];

    printf("Please input your name.... ");
    scanf( "%s%*c" , s );

    printf("Please select your department.... (a:資工 b:電機 c:電子) ");
    scanf( "%c" , &c );

    printf("Please input your score on test 1 .... ");
    scanf( "%d" , &a );

    printf("Please input your score on test 2 .... ");
    scanf( "%d" , &b );

    printf("|-------------------------------------------|\n");
    printf("|   Name   |Department|Test 1|Test 2|Average|\n");
    printf("|-------------------------------------------|\n");
    printf("|%-10s|%-10c|%6d|%6d|%7.2f|\n", s , c , a , b , (a+b)/2.0 );
    printf("|-------------------------------------------|\n");
}