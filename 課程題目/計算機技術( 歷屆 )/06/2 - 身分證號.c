#include <stdio.h>

int main()
{
    char id[11] ,  tmpe[26] = "ABCDEFGHJKLMNPQRSTUVXYWZIO";
    int weight[9] = {8,7,6,5,4,3,2,1,1} , sum = 0 , tmpm[26];
    for ( int i = 0 ; i < 26 ; i++ )
        tmpm[i] = 10 + i;
    scanf("%s", id);
    for ( int i = 0 ; i < 10 ; i++)
    {
        if ( i == 0 )
            for ( int j = 0 ; j < 26 ; j++ )
            {
                if ( id[0] == tmpe[j] )
                {
                    sum = (tmpm[j] / 10 + (tmpm[j] % 10) * 9);
                    break;
                }
            }
        else
            sum += (id[i] - '0') * weight[i - 1];
    }
    if ( sum % 10 == 0 )
        printf("身份證字號正確!!\n");
    else
        printf("身份證字號錯誤!!\n");
}