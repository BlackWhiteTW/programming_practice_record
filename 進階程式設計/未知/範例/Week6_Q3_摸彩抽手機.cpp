#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    for (int day = 0; day < k; day++)
    {
        int x, y, z;
        cin >> x >> y >> z;

        vector<int> valid;
        for (int num = x + 1; num < y; num++)
        {
            if (num % z != 0)
            {
                valid.push_back(num);
            }
        }

        if (valid.empty())
        {
            cout << "null\n";
        }
        else
        {
            for (int i = 0; i < valid.size(); i++)
            {
                if (i > 0)
                    cout << " ";
                cout << valid[i];
            }
            cout << "\n";
        }
    }

    return 0;
}
