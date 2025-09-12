#include <bits/stdc++.h>

using namespace std;

int main()
{
    int p;
    float ans = 0;
    cin >> p;
    for ( int i = 0 ; i < p ; i++ )
    {
        int tmp;
        cin >> tmp;
        ans += tmp;
    }
    ans /= p;
    cout << ans;
}