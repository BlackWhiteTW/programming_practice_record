#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a , ans = 0;
    cin >> a;
    if ( a % 5 == 0)
        ans = a / 5;
    else
        ans = a / 5 + 1;

    cout << ans << endl;

    return 0;
}