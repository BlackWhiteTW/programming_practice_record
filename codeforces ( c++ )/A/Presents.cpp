#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p,tmp;
    cin >> p;
    int a[p];
    for ( int i = 0 ; i < p ; i++)
    {
        cin >> tmp;
        a[tmp-1] = i+1;
    }
    for ( int i = 0 ; i < p ; i++)
        cout << a[i] << " ";
}