#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct State
{
    vector<int> path;
    vector<bool> visited;
};

void bfs(int n)
{
    queue<State> q;

    State start;
    start.visited = vector<bool>(n + 1, false);
    q.push(start);

    while (!q.empty())
    {
        State curr = q.front();
        q.pop();

        if (curr.path.size() == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << (char)(curr.path[i] + 'a' - 1);
            }
            cout << "\n";
            continue;
        }

        for (int i = 1; i <= n; i++)
        {
            if (!curr.visited[i])
            {
                State next_state = curr;
                next_state.path.push_back(i);
                next_state.visited[i] = true;
                q.push(next_state);
            }
        }
    }
}

int main()
{
    while (1)
    {
        int n;
        cin >> n;
        if (n == 0)
            break;
        bfs(n);
    }
}