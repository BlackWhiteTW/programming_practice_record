#include<stdio.h>
#include<string.h>

#define MAX_STATE 5000000

int memo[MAX_STATE];

typedef struct
{
    int number[12];
    char ch[12];
    int index;
    int len;
} Node;

/*
dfs 找出所有可能 (使用 Memoization 優化)
*/
int dfs( int n , Node array[] )
{
    // 計算當前狀態的 Hash 值 (Base 13)
    int state = 0;
    int multiplier = 1;
    for(int i = 0; i < n; i++) {
        state += array[i].index * multiplier;
        multiplier *= 13;
    }

    // 如果此狀態已經計算過，直接回傳
    if(memo[state] != -1) return memo[state];

    int max_gain = 0;

    for ( int i = 0 ; i < n - 1 ; i++ )
    {
        if ( array[i].index >= array[i].len ) continue;
        
        for ( int j = i + 1 ; j < n ; j++ )
        {
            if ( array[j].index >= array[j].len ) continue;

            if ( array[i].ch[array[i].index] == array[j].ch[array[j].index] )
            {
                int gain = array[i].number[array[i].index] + array[j].number[array[j].index];
                
                array[i].index++;
                array[j].index++;
                
                int temp = gain + dfs( n , array );
                if ( temp > max_gain )
                    max_gain = temp;
                
                array[i].index--;
                array[j].index--;
            }
        }
    }
    return memo[state] = max_gain;
}

int main()
{
    // 初始化 memo 陣列
    memset(memo, -1, sizeof(memo));

    int n , max_len = 0;
    scanf( "%d" , &n );
    Node array[n];
    memset(array, 0, sizeof(array));
    for ( int i = 0 ; i < n ; i++ )
    {
        scanf( "%d" , &array[i].len );
        for ( int j = 0 ; j < array[i].len ; j++ )
            scanf( " %c %d" , &array[i].ch[j] , &array[i].number[j] );
        if ( array[i].len > max_len )
            max_len = array[i].len;
    }
    int ans = dfs( n , array );
    printf( "%d\n" , ans );
}