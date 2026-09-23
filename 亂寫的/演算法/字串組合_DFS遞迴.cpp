#include <bits/stdc++.h>

using namespace std;

bool dfs(const vector<vector<char>> &c_arr, vector<vector<bool>> &b_arr, int map_x, int map_y, const string &ans, int in_x, int in_y, int index)
{
    if (index == ans.size() - 1)
        return true;
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++)
    {
        int tx = in_x + dx[i], ty = in_y + dy[i];
        if (tx >= 0 && tx < map_x && ty >= 0 && ty < map_y)
        {
            if (!b_arr[tx][ty] && c_arr[tx][ty] == ans[index + 1])
            {
                b_arr[tx][ty] = true;
                if (dfs(c_arr, b_arr, map_x, map_y, ans, tx, ty, index + 1))
                    return true;
                b_arr[tx][ty] = false;
            }
        }
    }
    return false;
}

int main()
{
    int n, m;
    string ans;
    cin >> n >> m >> ans;
    vector<vector<char>> c_arr(n, vector<char>(m));
    vector<vector<bool>> b_arr(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c_arr[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (c_arr[i][j] == ans[0])
            {
                b_arr[i][j] = true;
                if (dfs(c_arr, b_arr, n, m, ans, i, j, 0))
                {
                    cout << "YES" << endl;
                    return 0;
                }
                b_arr[i][j] = false;
            }
        }
    }
    cout << "NO" << endl;
}