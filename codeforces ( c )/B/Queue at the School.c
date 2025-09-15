#include <stdio.h>

int main()
{
    int n , t;
    char s[51];
    scanf("%d %d", &t, &n);
    scanf("%s", s);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < t; j++)
        {
            if (s[j] == 'B' && s[j + 1] == 'G')
            {
                char temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
                j++;
            }
        }
    }
    printf("%s\n", s);
}