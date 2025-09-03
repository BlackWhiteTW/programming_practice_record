#include <bits/stdc++.h>

using namespace std;

int main()
{
    int rt , x1 , x2 = 0 , y1 , y2 = 0 , z1 , z2 = 0;
    cin >> rt;
    for ( int i = 0 ; i < rt ; i++ )
    {
        cin >> x1 >> y1 >> z1;
        x2 += x1;
        y2 += y1;
        z2 += z1;
    }

    if ( x2 == 0 && y2 == 0 && z2 == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}