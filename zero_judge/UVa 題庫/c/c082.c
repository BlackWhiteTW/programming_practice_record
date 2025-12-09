#include<stdio.h>

int main()
{
    int x , y , map[51][51] = {0};
    scanf( "%d %d" , &x , &y );
    int x_s , y_s , nesw_i = 0 , x_t , y_t;
    char nesw[4] = { 'N' , 'E' , 'S' , 'W' } , s_nesw = ' ';
    while( ( scanf( "%d %d %c" , &x_s , &y_s , &s_nesw ) ) != EOF )
    {
        for ( int i = 0 ; i < 4 ; i++ )
            if ( s_nesw == nesw[i] )
                nesw_i = i;
        
        char str[101] = "";
        scanf( "%s" , str );
        for ( int i = 0 ; str[i] != '\0' ; i++ )
        {
            if ( str[i] == 'R' )
                nesw_i = ( nesw_i + 1 ) % 4;
            else if ( str[i] == 'L' )
                nesw_i = ( nesw_i + 3 ) % 4;
            else
            {
                y_t = y_s , x_t = x_s;
                switch ( nesw_i )
                {
                    case 0:
                        y_s++;
                        break;
                    case 1:
                        x_s++;
                        break;
                    case 2:
                        y_s--;
                        break;
                    case 3:
                        x_s--;
                        break;
                }
            }

            if ( x_s < 0 || x_s > x || y_s < 0 || y_s > y )
            {
                if ( map[y_t][x_t] == 0 )
                {
                    printf( "%d %d %c LOST\n" , x_t , y_t , nesw[nesw_i] );
                    map[y_t][x_t] = 1;
                    break;
                }
                else
                    x_s = x_t , y_s = y_t;
            }
        }
        if ( x_s >= 0 && x_s <= x && y_s >= 0 && y_s <= y )
            printf( "%d %d %c\n" , x_s , y_s , nesw[nesw_i] );
    }
}