#include <bits/stdc++.h>

using namespace std;

bool dfs(const vector<vector<char>> &c_arr, vector<vector<int>> &i_arr, int map_x, int map_y, const string &ans)
{
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    for (int i = 0; i < map_x; i++)
    {
        for (int j = 0; j < map_y; j++)
        {
            if (c_arr[i][j] == ans[0])
            {
                stack<tuple<int, int, int, int>> s;
                s.push({i, j, 0, 0});
                while (!s.empty())
                {
                    auto [nx, ny, nc, flag] = s.top();
                    if (nc == ans.size() - 1)
                    {
                        return true;
                    }
                    i_arr[nx][ny] = 1;
                    s.pop();
                    if (flag < 4)
                    {
                        s.push({nx, ny, nc, flag + 1});
                        int tx = nx + dx[flag], ty = ny + dy[flag];
                        if (tx >= 0 && tx < map_x && ty >= 0 && ty < map_y)
                        {
                            if (!i_arr[tx][ty] && c_arr[tx][ty] == ans[nc + 1] && i_arr[tx][ty] == 0)
                            {
                                s.push({tx, ty, nc + 1, 0});
                            }
                        }
                    }
                    else
                    {
                        i_arr[nx][ny] = 0;
                    }
                }
            }
            for (int k = 0; k < map_x; k++)
                for (int l = 0; l < map_y; l++)
                    i_arr[k][l] = 0;
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
    vector<vector<int>> i_arr(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> c_arr[i][j];
        }
    }
    bool flag = dfs(c_arr, i_arr, n, m, ans);
    if (flag)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}