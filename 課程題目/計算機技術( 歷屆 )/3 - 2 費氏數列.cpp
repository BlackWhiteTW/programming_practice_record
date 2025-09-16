#include <bits/stdc++.h>

using namespace std;

int n = 0;

void array(int a , int b , int c)
{
    if ( a > n ) 
        return;
    cout << c << ", ";
    if ( c == 0 )
        array(a + 1 , b , 1);
    else
        array(a + 1 , c , b + c);
}
int main()
{
    cout << "Please input a number:";
    cin >> n;
    array(1 , 0 , 0);
    
    system("pause");
    return 0;
}