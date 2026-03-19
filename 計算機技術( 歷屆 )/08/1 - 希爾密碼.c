#include <stdio.h>

int encode ( char en )
{
    if ( en >= 'A' && en <= 'Z' )
        return en - 'A';
    else if ( en >= 'a' && en <= 'z' )
        return en - 'a';
    else
        return -1;
}

int int_to_array ( int arr[] , int en[] , int times )
{
    int ans = 0;
    ans += arr[times*3] * en[0];
    ans += arr[times*3+1] * en[1];
    ans += arr[times*3+2] * en[2];
    return ans % 26;
}

int main()
{
    int array[9] , en1[3] , en2[3] , en3[3] , en4[3] , ans[12];
    char en[13] = "" ;

    printf("Please int a 3x3 key matrix (9 integers): ");
    for ( int i = 0; i < 9; i++ )
        scanf("%d", &array[i]);

    printf("Please input a string: ");
    scanf(" %s", en);

    for ( int i = 0; i < 3; i++ )
    {
        en1[i] = encode(en[i]);
        en2[i] = encode(en[i+3]);
        en3[i] = encode(en[i+6]);
        en4[i] = encode(en[i+9]);
    }

    for ( int i = 0; i < 3; i++ )
    {
        ans[i] = int_to_array(array, en1 , i);
        ans[i+3] = int_to_array(array, en2 , i);
        ans[i+6] = int_to_array(array, en3 , i);
        ans[i+9] = int_to_array(array, en4 , i);
    }

    for ( int i = 0; i < 12; i++ )
        printf("%c", ans[i] + 'A');
}
