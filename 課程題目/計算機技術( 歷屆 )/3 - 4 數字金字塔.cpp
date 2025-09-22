#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Please input a number: ";
    cin >> n;
    for ( int i = 1 ; i <= n ; i++ )
    {
        for ( int j = n - i ; j >= 1 ; j-- )
            cout << " ";
        for ( int j = 1 ; j <= i * 2 - 1; j++ )
        {
            if ( j <= i )
                cout << (j % 10);
            else
                cout << ((i * 2 - j) % 10);
        }
        cout << endl;
    }

    system("pause");
    return 0;
}