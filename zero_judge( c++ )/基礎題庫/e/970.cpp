#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int seed, ans = 0;
    seed = arr[n - 1];
    for (int i = 0; i < n; i++)
    {
        if (i % seed == 0)
            ans += arr[i];
    }
    ans %= n;
    if (ans == 0)
        ans = n;
    cout << ans << " " << arr[ans - 1] << endl;
}