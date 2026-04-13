#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    while (1)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        int temp = a + b, count = 1, ans = 0;
        while (temp / count)
        {
            if ((temp / count % 10) < (a / count % 10) + (b / count % 10))
                ans++;
            count *= 10;
        }
        if (ans == 0)
            cout << "No carry operation." << endl;
        else if (ans == 1)
            cout << "1 carry operation." << endl;
        else
            cout << ans << " carry operations." << endl;
    }
}