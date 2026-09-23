#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x, y, step;
};

int bfs(vector<vector<int>> &arr, vector<pair<int, int>> &temp, int map_x, int map_y)
{
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    queue<Node> q;
    q.push({0, 0, 0});
    arr[0][0] = 1;
    while (!q.empty())
    {
        Node node = q.front();
        int x = node.x, y = node.y, step = node.step + 1;
        q.pop();
        if (x == map_x - 1 && y == map_y - 1)
            return step;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < map_x && ny >= 0 && ny < map_y)
            {
                if (arr[nx][ny] == 0)
                {
                    q.push({nx, ny, step});
                    arr[nx][ny] = 1;
                }
                if (arr[nx][ny] == 2)
                {
                    while (!temp.empty())
                    {
                        q.push({temp.back().first, temp.back().second, step});
                        arr[temp.back().first][temp.back().second] = 1;
                        temp.pop_back();
                    }
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
    vector<vector<int>> arr(n, vector<int>(m));
    vector<pair<int, int>> temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                temp.push_back({i, j});
        }
    }
    cout << bfs(arr, temp, n, m) << endl;
    return 0;
}