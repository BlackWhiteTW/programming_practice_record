#include <bits/stdc++.h>

using namespace std;

int main()
{
    for ( int i = 1 ; i < 10 ; i++ )
    {
        for ( int j = 1 ; j < 10 ; j++ )
            cout << j << "*" << i << "=" << left << setw(2) << i * j << " ";
        cout << endl;
    }
    system("pause");
    return 0; 
}