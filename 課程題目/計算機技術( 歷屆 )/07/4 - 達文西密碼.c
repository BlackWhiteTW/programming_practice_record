#include <stdio.h>
#include <string.h>

int char_to_ascii (char ch)
{
    if ( ch >= 'A' && ch <= 'Z' )
        return ch - 'A';
    else if ( ch >= 'a' && ch <= 'z' )
        return ch - 'a';
    else
        return -1;
}

int en_check (int en1[26] , int en2[26])
{
    for ( int i = 0 ; i < 26; i++ )
    {
        if ( en1[i] != en2[i] )
        {
            printf("No\n");
            return 0;
        }
    }
    return 1;
}

int main()
{
    char str1[51] = "", str2[51] = "";
    int str1_en[26] = {0}, str2_en[26] = {0};
    printf("Please input a string #1: ");
    scanf("%[^\n]%*c", str1);
    printf("Please input a string #2: ");
    scanf("%[^\n]%*c", str2);

    for ( int i = 0; str1[i] != '\0'; i++ )
    {
        int index = char_to_ascii(str1[i]);
        if (index != -1)
            str1_en[index]++;
    }

    for ( int i = 0; str2[i] != '\0'; i++ )
    {
        int index = char_to_ascii(str2[i]);
        if (index != -1)
            str2_en[index]++;
    }

    printf("%s\n", (en_check(str1_en, str2_en) == 0) ? "No" : "Yes");
}