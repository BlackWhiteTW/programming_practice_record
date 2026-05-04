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
        char s;
        int m, n;
        cin >> s >> m >> n;

        if (m == 1)
        {
            // Pattern 1: incrementing
            for (int row = 1; row <= n; row++)
            {
                for (int col = 0; col < row; col++)
                {
                    cout << s;
                }
                cout << "\n";
            }
        }
        else if (m == 2)
        {
            // Pattern 2: decrementing
            for (int row = n; row >= 1; row--)
            {
                for (int col = 0; col < row; col++)
                {
                    cout << s;
                }
                cout << "\n";
            }
        }
    }

    return 0;
}
