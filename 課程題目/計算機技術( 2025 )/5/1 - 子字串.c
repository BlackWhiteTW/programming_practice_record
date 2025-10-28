#include <stdio.h>
#include <string.h>

int str = 0 , i , j , k;

void str2_in_str1 (char s1[] , char s2[])
{
    for (k = 0; s1[k]; k++)
    {
        if ( ( s1[k] != s2[k] ) && ( s2[k] != '\0' ) )
            return;
    }
    str++;
}

int main()
{
    int s1_len , s2_len;
    char s1[101] = "" , s2[101] = "";

    printf("Please input the string 1: ");
    scanf("%s", s1);
    printf("Please input the string 2: ");
    scanf("%s", s2);

    for (i = 0; i < strlen(s1) - strlen(s2); i++)
    {
        char tmp[strlen(s2)] = "";
        for (j = 0; j < strlen(s2); j++)
            tmp[j] = s1[i + j];
        str2_in_str1(tmp , s2);

    }
    if (str == 0)
        printf("String 2 is not a substring of String 1\n");
    else
    {
        printf("String 2 is a substring of String 1\n");
        printf("Repeat %d times\n", str);
    }
}