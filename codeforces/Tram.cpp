#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n , ans = 0 , tmp = 0;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
    {
        int a , b;
        cin >> a >> b;
        tmp -= a;
        tmp += b;
        if (ans < tmp)
            ans = tmp;
    }
    
    cout << ans << endl;
    return 0;
}
