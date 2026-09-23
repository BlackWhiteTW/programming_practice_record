#include <bits/stdc++.h>

using namespace std;

void dfs(vector<char> &c_arr, int n, vector<bool> &b_list, long long int &t)
{
    if (c_arr.size() == n)
    {
        for (int i = 0; i < n; i++)
            cout << c_arr[i];
        cout << endl;
        t++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (!b_list[i])
        {
            b_list[i] = true;
            c_arr.push_back(static_cast<char>('a' + i));
            dfs(c_arr, n, b_list, t);
            c_arr.pop_back();
            b_list[i] = false;
        }
    }
}

int main()
{
    long long int t = 0;
    int n;
    cin >> n;
    vector<char> c_arr;
    vector<bool> b_list(n, false);
    dfs(c_arr, n, b_list, t);
    cout << t << endl;
}