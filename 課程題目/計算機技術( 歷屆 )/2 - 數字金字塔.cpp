#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cout << "Please input a number:";
    cin >> n;
    for ( int i = 1 ; i < n + 1 ; i++ )
    {
        for ( int j = 1 ; j < n - i + 1; j++ )
            cout << " ";
        for ( int k = 1 ; k < ( i - 1 ) * 2 + 1 ; k++ )
            cout << i % 10;
        cout << endl;
    }
}