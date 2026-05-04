#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> grid[i][j];
        }
    }

    int grayBlocks = 0, whiteBlocks = 0;

    // BFS 找連通分量
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j] && grid[i][j] != 2)
            {
                // 找到未訪問的乾淨地磚
                int color = grid[i][j];
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = true;

                // BFS 遍歷同色連通分量
                while (!q.empty())
                {
                    auto [x, y] = q.front();
                    q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int nx = x + dx[k];
                        int ny = y + dy[k];

                        if (nx >= 0 && nx < N && ny >= 0 && ny < N &&
                            !visited[nx][ny] && grid[nx][ny] == color)
                        {
                            visited[nx][ny] = true;
                            q.push({nx, ny});
                        }
                    }
                }

                // 統計區塊
                if (color == 1)
                {
                    grayBlocks++;
                }
                else
                {
                    whiteBlocks++;
                }
            }
        }
    }

    cout << grayBlocks << " " << whiteBlocks << endl;

    return 0;
}
