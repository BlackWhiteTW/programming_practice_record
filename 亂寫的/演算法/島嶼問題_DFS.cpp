#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &v, vector<vector<bool>> &visited, int x, int y, int m, int n)
{
    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || v[x][y] == 0)
        return;
    visited[x][y] = true;
    if (v[x][y] == 0)
        return;
    dfs(v, visited, x + 1, y, m, n);
    dfs(v, visited, x - 1, y, m, n);
    dfs(v, visited, x, y + 1, m, n);
    dfs(v, visited, x, y - 1, m, n);
}

int main()
{
    int n, m, count = 0;
    cin >> n >> m;
    vector<vector<int>> v(m, vector<int>(n, 0));
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> v[i][j];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j] && v[i][j] == 1)
            {
                dfs(v, visited, i, j, m, n);
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}

/*
5 5
1 1 0 0 0
1 1 0 0 0
0 0 1 0 0
0 0 0 1 1
0 0 0 1 1

3
*/