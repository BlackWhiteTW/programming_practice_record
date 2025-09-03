#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0 , tmp;
    for ( int i = 0 ; i < 5 ; i++ )
    {
        for ( int j = 0 ; j < 5 ; j++ )
        {
            cin >> tmp;
            if ( tmp == 1)
            {
                ans = abs(i - 2) + abs(j - 2);
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}