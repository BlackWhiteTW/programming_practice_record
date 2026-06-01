#include <bits/stdc++.h>

using namespace std;

void bfs(vector<vector<char>> &v, int n, int m, int start_x, int start_y, int end_x, int end_y)
{
    queue<pair<int, int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));
    q.push({start_x, start_y});
    dist[start_x][start_y] = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && v[new_x][new_y] != '#' && dist[new_x][new_y] == -1)
            {
                dist[new_x][new_y] = dist[x][y] + 1;
                q.push({new_x, new_y});
            }
        }
        if (x == end_x && y == end_y)
        {
            cout << dist[x][y] << endl;
            return;
        }
    }
    cout << "-1" << endl;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> v(n, vector<char>(m, '.'));
    int start_x, start_y, end_x, end_y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'S')
            {
                start_x = i;
                start_y = j;
            }
            else if (v[i][j] == 'E')
            {
                end_x = i;
                end_y = j;
            }
        }
    bfs(v, n, m, start_x, start_y, end_x, end_y);
    return 0;
}