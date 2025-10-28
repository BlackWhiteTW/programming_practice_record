#include <stdio.h>

int main()
{
    while ( 1 )
    {
        int sum = 0 , i , cn_arr_int[16] = {0} , cn = 0 , error = 0;
        char cn_arr[17] = "";
        printf("請輸入卡號: ");
        scanf("%s", cn_arr);
        for (i = 0; i < 16; i++)
        {
            if (cn_arr[i] == '\0' && i != 15)
            {
                error = 1;
                break;
            }
            if ( (cn_arr[i] < '0' || cn_arr[i] > '9' ) && cn_arr[i] != '\0' )
            {
                error = 1;
                break;
            }
            if ( cn_arr[i] == '\0' && i == 15 )
            {
                cn = 1;
                break;
            }
            cn_arr_int[i] = cn_arr[i] - '0';
        }
        if ( error == 1 )
        {
            printf("卡號輸入錯誤\n");
            return 0;
        }
        for ( i = 0 ; i < 16 ; i++ )
        {
            if ( cn == 0 )
            {
                if ( i % 2 == 0 )
                    if ( cn_arr_int[i] * 2 > 9 )
                        sum += cn_arr_int[i] * 2 - 9;
                    else
                        sum += cn_arr_int[i] * 2;
                else
                    sum += cn_arr_int[i];
            }
            else
            {
                if ( i % 2 != 0 )
                    if ( cn_arr_int[i] * 2 > 9 )
                        sum += cn_arr_int[i] * 2 - 9;
                    else
                        sum += cn_arr_int[i] * 2;
                else
                    sum += cn_arr_int[i];
            }
        }
        if ( sum % 10 != 0 )
            printf("卡號錯誤\n");
        else
            printf("卡號正確\n");
    }
    
}