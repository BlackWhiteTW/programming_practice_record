#include <bits/stdc++.h>

using namespace std;

pair<int, int> dfs(vector<vector<bool>> &b_arr, int x, int y)
{
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    int max_chunk = 0, chunk_num = 0;
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < y; j++)
        {
            if (b_arr[i][j] == false)
            {
                int temp_chunk = 0;
                chunk_num++;
                stack<pair<int, int>> s;
                s.push({i, j});
                b_arr[i][j] = true;
                while (!s.empty())
                {
                    int nx = s.top().first, ny = s.top().second;
                    s.pop();
                    b_arr[nx][ny] = true;
                    for (int k = 0; k < 4; k++)
                    {
                        int tx = nx + dx[k], ty = ny + dy[k];
                        if (tx >= 0 && tx < x && ty >= 0 && ty < y)
                        {
                            if (b_arr[tx][ty] == false)
                            {
                                s.push({tx, ty});
                                b_arr[tx][ty] = true;
                            }
                        }
                    }
                    temp_chunk++;
                }
                max_chunk = max(max_chunk, temp_chunk);
            }
        }
    }
    return {chunk_num, max_chunk};
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> b_arr(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            if (temp == 0)
                b_arr[i][j] = true;
        }
    }
    pair<int, int> ans = dfs(b_arr, n, m);
    cout << ans.first << " " << ans.second << endl;
}