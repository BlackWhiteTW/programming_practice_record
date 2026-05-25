#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        vector<char> v;

        for (int i = 0; i < n; i++)
            v.push_back(i + 'a');

        do
        {
            for (int i = 0; i < n; i++)
            {
                cout << v[i] << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
        } while (next_permutation(v.begin(), v.end()));
    }
    return 0;
}