#include <bits/stdc++.h>

using namespace std;

int bfs(vector<vector<bool>> &b_arr, int map_x, int map_y)
{
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    b_arr[0][0] = true;
    while (!q.empty())
    {
        auto [x, y, step] = q.front();
        q.pop();
        if (x == map_x - 1 && y == map_y - 1)
            return step;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < map_x && ny >= 0 && ny < map_y)
            {
                if (b_arr[nx][ny] == false)
                {
                    q.push({nx, ny, step + 1});
                    b_arr[nx][ny] = true;
                }
            }
        }
    }
    return -1;
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
            if (temp == 1)
                b_arr[i][j] = true;
        }
    }
    cout << bfs(b_arr, n, m) << endl;
    return 0;
}