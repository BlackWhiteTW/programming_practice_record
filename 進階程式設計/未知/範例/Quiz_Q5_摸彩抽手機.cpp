#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int x, y, z;
        char comma1, comma2;
        cin >> x >> comma1 >> y >> comma2 >> z;

        vector<int> results;
        for (int num = x; num <= y; num++)
        {
            if (num % z != 0)
            {
                results.push_back(num);
            }
        }

        if (results.empty())
        {
            cout << "null" << endl;
        }
        else
        {
            for (int j = 0; j < results.size(); j++)
            {
                if (j > 0)
                    cout << " ";
                cout << results[j];
            }
            cout << endl;
        }
    }

    return 0;
}
