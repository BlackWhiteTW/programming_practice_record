#include <bits/stdc++.h>

using namespace std;

int n = 0;

void fes(int a, int b, int c)
{
    if ( a > n ) 
        return;
    if ( a == n )
        cout << c << endl;
    else
        cout << c << ", ";
    if ( c == 0 )
        fes(a + 1 , b , 1);
    else
        fes(a + 1 , c , b + c);
}

int main()
{
    cout << "Please input a number:";
    cin >> n;
    fes(1 , 0 , 0);
    
    system("pause");
    return 0;
}