#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x, y, step;
};

int bfs(vector<vector<bool>> &b_arr, int map_x, int map_y)
{
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    queue<Node> q;
    q.push({0, 0, 0});
    if (b_arr[0][0] == true)
        return -1;
    b_arr[0][0] = true;
    while (!q.empty())
    {
        Node node = q.front();
        q.pop();
        if (node.x == map_x - 1 && node.y == map_y - 1)
            return node.step;
        for (int i = 0; i < 4; i++)
        {
            int nx = node.x + dx[i], ny = node.y + dy[i];
            if (nx >= 0 && nx < map_x && ny >= 0 && ny < map_y)
            {
                if (b_arr[nx][ny] == false)
                {
                    q.push({nx, ny, node.step + 1});
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