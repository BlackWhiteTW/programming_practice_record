#include <bits/stdc++.h>

using namespace std;

void bfs(const vector<vector<char>> &v, int n, int m, int start_x, int start_y, int end_x, int end_y)
{
    cout << "起點: " << start_x << " " << start_y << endl;
    cout << "終點: " << end_x << " " << end_y << endl;
    vector<vector<int>> visited(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    q.push({start_x, start_y});
    visited[start_x][start_y] = 0;
    int dx[] = {0, 0, 1, -1};
    int dy[] = {1, -1, 0, 0};
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        cout << "目前位置: " << x << " " << y << endl;
        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];
            if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && v[new_x][new_y] != '#' && visited[new_x][new_y] == -1)
            {
                visited[new_x][new_y] = visited[x][y] + 1;
                q.push({new_x, new_y});
            }
        }
        if (x == end_x && y == end_y)
        {
            cout << "最短距離: " << visited[x][y] << endl;
            break;
        }
    }
    if (visited[end_x][end_y] == -1)
        cout << "最短距離: " << visited[end_x][end_y] << endl;
    return;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<vector<char>> v(n, vector<char>(m, '.'));
    int start_x, start_y, end_x, end_y;
    // input == S , . , # , E
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 'S')
            {
                start_x = i;
                start_y = j;
            }
            if (v[i][j] == 'E')
            {
                end_x = i;
                end_y = j;
            }
        }
    }
    bfs(v, n, m, start_x, start_y, end_x, end_y);
}

/*
S . . . .
. # . # .
. . . . .
# . # . E
. . . . .
*/