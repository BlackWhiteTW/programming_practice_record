#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int x, y, step;
};

int bfs(vector<vector<int>> &arr, int map_x, int map_y)
{
    int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
    queue<Node> q;
    q.push({0, 0, 1});
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
                if (arr[nx][ny] == 0)
                {
                    q.push({nx, ny, node.step + 1});
                    arr[nx][ny] = 1;
                }
                if (arr[nx][ny] == 2)
                {
                    for (int j = 0; j < map_x; j++)
                    {
                        for (int k = 0; k < map_y; k++)
                        {
                            if (arr[j][k] == 2)
                            {
                                q.push({j, k, node.step + 1});
                                arr[j][k] = 1;
                            }
                        }
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    cout << bfs(arr, n, m) << endl;
}

/*
6 6
0 0 0 1 0 0
0 1 0 1 0 1
2 0 0 0 0 0
1 1 1 1 1 0
0 0 0 0 2 0
0 1 1 1 1 0
5
*/