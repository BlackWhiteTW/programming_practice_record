#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y, z;
        bool output = 0;
        cin >> x >> y >> z;
        for (int j = x + 1; j < y; j++)
            if (j % z != 0)
            {
                cout << j << " ";
                output = 1;
            }
        if (!output)
            cout << "null";
        cout << endl;
    }
}