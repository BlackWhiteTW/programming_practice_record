#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> v;
    string s;
    while (getline(cin, s))
        v.push_back(s);
    int n = 0;
    for (int i = v.size() - 1; i >= 0; i--)
        if (n < v[i].size())
            n = v[i].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = v.size() - 1; j >= 0; j--)
        {
            if (i < v[j].size())
                cout << v[j][i];
            else
                cout << " ";
        }
        cout << endl;
    }
}