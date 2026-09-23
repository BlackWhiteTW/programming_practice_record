#include <bits/stdc++.h>

using namespace std;

pair<int, int> dfs(vector<vector<int>> &i_arr, vector<vector<bool>> &b_arr, int x, int y)
{
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    int a = 0, b = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (!b_arr[i][j])
            {
                if (i_arr[i][j] == 1)
                    a++;
                else
                    b++;
                int flag = i_arr[i][j];
                stack<pair<int, int>> s;
                s.push({i, j});
                b_arr[i][j] = true;
                while (!s.empty())
                {
                    int ix = s.top().first, iy = s.top().second;
                    s.pop();
                    b_arr[ix][iy] = true;
                    for (int k = 0; k < 4; k++)
                    {
                        int new_x = ix + dx[k], new_y = iy + dy[k];
                        if (new_x >= 0 && new_x < x && new_y >= 0 && new_y < y && !b_arr[new_x][new_y] && i_arr[new_x][new_y] == i_arr[ix][iy])
                        {
                            if (i_arr[new_x][new_y] == flag)
                            {
                                s.push({new_x, new_y});
                                b_arr[new_x][new_y] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    return {a, b};
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> i_arr(n, vector<int>(n));
    vector<vector<bool>> b_arr(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> i_arr[i][j];
            if (i_arr[i][j] == 2)
                b_arr[i][j] = true;
        }
    }
    pair<int, int> ans;
    ans = dfs(i_arr, b_arr, n, n);
    cout << ans.first << " " << ans.second << endl;
}