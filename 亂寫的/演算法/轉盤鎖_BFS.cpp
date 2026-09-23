#include <bits/stdc++.h>

using namespace std;

struct Node
{
    vector<char> list_c;
    int step;
};

int bfs(vector<char> &list1, vector<vector<char>> &list2, int a, int b)
{
    set<vector<char>> visited;
    for (int i = 0; i < b; i++)
    {
        visited.insert(list2[i]);
    }
    queue<Node> q;
    vector<char> start_list(a, '0');
    for (int i = 0; i < a; i++)
    {
        start_list[i] = '0';
    }
    if (visited.count(start_list) || visited.count(list1))
        return -1;
    if (start_list == list1)
        return 0;
    q.push({start_list, 0});
    visited.insert(start_list);
    while (!q.empty())
    {
        Node node = q.front();
        q.pop();
        if (node.list_c == list1)
            return node.step;
        // 修正後的轉盤搜尋邏輯
        for (int i = 0; i < a; i++)
        { // 遍歷每一個轉盤
            char original = node.list_c[i];

            // +1 轉法 (若為 '9' 則變回 '0')
            char next_add = (original == '9' ? '0' : original + 1);
            // -1 轉法 (若為 '0' 則變回 '9')
            char next_sub = (original == '0' ? '9' : original - 1);

            // 檢查 +1 的狀態
            vector<char> new_list_add = node.list_c;
            new_list_add[i] = next_add;
            if (visited.count(new_list_add) == 0)
            {
                visited.insert(new_list_add);
                q.push({new_list_add, node.step + 1});
            }

            // 檢查 -1 的狀態
            vector<char> new_list_sub = node.list_c;
            new_list_sub[i] = next_sub;
            if (visited.count(new_list_sub) == 0)
            {
                visited.insert(new_list_sub);
                q.push({new_list_sub, node.step + 1});
            }
        }
    }
    return -1;
}

int main()
{
    int a, b;
    cin >> a >> b;
    vector<char> list1(a);
    for (int i = 0; i < a; i++)
    {
        cin >> list1[i];
    }
    vector<vector<char>> list2(b, vector<char>(a));
    for (int i = 0; i < b; i++)
    {
        for (int j = 0; j < a; j++)
        {
            cin >> list2[i][j];
        }
    }
    cout << bfs(list1, list2, a, b) << endl;
}