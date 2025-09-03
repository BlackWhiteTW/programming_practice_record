#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k , n , w;
    cin >> k >> n >> w;
    k = k * w * ( w + 1 ) / 2;
    int ans = k - n;
    cout << ( ans > 0 ? ans : 0 );
}