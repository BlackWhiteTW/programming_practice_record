#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    long long ans = 0;
    cout << "N = ";
    cin >> n;
    for (int i = 1; i < n / 4; i++)
        for (int j = i + 1; j < n / 3; j++)
        {
            int s = j + 1;
            int e = (n - i - j - 1) / 2;
            if (s <= e)
                ans += e - s + 1;
        }
    cout << "Total is " << ans << "." << endl;

    system("pause");
    return 0;
}