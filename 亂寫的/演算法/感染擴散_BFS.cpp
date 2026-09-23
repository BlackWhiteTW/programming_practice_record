#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x, y, t;
};

int bfs(vector<vector<int>> &arr, vector<vector<bool>> &b_arr, int map_x, int map_y)
{
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0}, maxt = 0;
    queue<Node> q;
    for (int i = 0; i < map_x; i++)
    {
        for (int j = 0; j < map_y; j++)
        {
            if (arr[i][j] == 2)
            {
                q.push({i, j, 0});
                b_arr[i][j] = true;
            }
        }
    }
    while (!q.empty())
    {
        Node node = q.front();
        q.pop();
        maxt = max(maxt, node.t);
        for (int i = 0; i < 4; i++)
        {
            int x = node.x + dx[i], y = node.y + dy[i], t = node.t + 1;
            if (x >= 0 && x < map_x && y >= 0 && y < map_y)
            {
                if (arr[x][y] == 1 && b_arr[x][y] == false)
                {
                    q.push({x, y, t});
                    b_arr[x][y] = true;
                    arr[x][y] = 2;
                }
            }
        }
    }
    for (int i = 0; i < map_x; i++)
    {
        for (int j = 0; j < map_y; j++)
        {
            if (arr[i][j] == 1 && b_arr[i][j] == false)
                return -1;
        }
    }
    return maxt;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<bool>> b_arr(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 0)
                b_arr[i][j] = true;
        }
    }
    cout << bfs(arr, b_arr, n, m) << endl;
    return 0;
}