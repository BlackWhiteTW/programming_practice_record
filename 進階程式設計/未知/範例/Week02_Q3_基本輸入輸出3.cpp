#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int m, n;
        char s;
        cin >> m >> n >> s;

        // Output m rows, each with n characters
        for (int row = 0; row < m; row++)
        {
            for (int col = 0; col < n; col++)
            {
                cout << s;
            }
            cout << "\n";
        }
    }

    return 0;
}
