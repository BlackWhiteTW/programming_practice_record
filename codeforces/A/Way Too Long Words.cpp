#include <bits/stdc++.h>

using namespace std;

int main()
{
    int i;
    cin >> i;
    for ( int h = 0 ; h < i ; h++ )
    {
        string str;
        cin >> str;
        if ( str.length() > 10 )
        {
            cout << str[0] << str.length() - 2 << str[str.length() - 1] << endl;
        }
        else
        {
            cout << str << endl;
        }
    }

    return 0;
}
