#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int l;
        cin >> l;
        vector<int> v(l);
        for (int j = 0; j < l; j++)
            cin >> v[j];

        int tip = 0;
        for (int j = 0; j < l; j++)
            for (int k = j + 1; k < l; k++)
                if (v[j] > v[k])
                {
                    tip++;
                    swap(v[j], v[k]);
                }
        cout << "Optimal train swapping takes " << tip << " swaps." << endl;
    }
}