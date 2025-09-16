#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n = 0 , a = 0 , b = 0 , c = 0;
    cout << "Please input a number:";
    cin >> n;
    for ( int i = 1 ; i <= n ; i++ )
    {
        if ( i == n )
            cout << b << endl;
        else
            cout << b << ", ";
        if ( b == 0 )
            b++;
        else
        {
            c = a + b;
            a = b;
            b = c;
        }
    }
    
    system("pause");
    return 0;
}