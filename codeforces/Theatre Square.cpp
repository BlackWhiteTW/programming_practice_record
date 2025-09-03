#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n , m , a , ans = 0;
    cin >> n >> m >> a;

    if ( n % a != 0 )
        n += a - n % a;
    if ( m % a != 0 )
        m += a - m % a;
    ans = (n / a) * (m / a);
    cout << ans;

    return 0;
}