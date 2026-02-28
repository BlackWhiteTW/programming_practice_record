#include <stdio.h>

int max_len = 0, regative = 0;

void input_number(int arr[], int *len)
{
    while (1)
    {
        arr[*len] = getchar() - '0';
        if (arr[*len] == '\n' - '0')
            break;
        (*len)++;
    }
}

void move_array(int arr[], int len)
{
    for (int i = len; i < max_len; i++)
    {
        for (int j = i; j >= 0; j--)
            arr[j + 1] = arr[j];
        arr[0] = 0;
    }
}

void sub_arrays(int a[], int b[], int c[])
{
    for (int i = max_len - 1; i >= 0; i--)
    {
        if (a[i] < b[i])
        {
            a[i] += 10;
            a[i - 1]--;
        }
        c[i] = a[i] - b[i];
    }
}

int main()
{
    int t = 0;
    scanf("%d", &t);
    getchar();
    for (int t_i = 0; t_i < t; t_i++)
    {
        int a[1024] = {0}, b[1024] = {0}, c[1024] = {0};
        int len_a = 0, len_b = 0, zero = 1;
        regative = 0;

        input_number(a, &len_a);
        input_number(b, &len_b);

        max_len = (len_a > len_b) ? len_a : len_b;
        move_array(a, len_a);
        move_array(b, len_b);

        for (int i = 0; i < max_len; i++)
        {
            if (a[i] > b[i])
                break;
            if (a[i] < b[i])
            {
                regative = 1;
                break;
            }
        }

        if (regative)
        {
            sub_arrays(b, a, c);
            printf("-");
        }
        else
            sub_arrays(a, b, c);

        for (int i = 0; i < max_len; i++)
        {
            if (zero && c[i] == 0)
                continue;
            zero = 0;
            printf("%d", c[i]);
        }
        printf("\n");
    }
}