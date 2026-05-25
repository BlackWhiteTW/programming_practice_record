#include <bits/stdc++.h>
using namespace std;

map<char, int> m;
int n;

void bfs(string s)
{
    if (s.size() == n)
    {
        cout << s << endl;
        return;
    }
    for (int i = 'a'; i < 'a' + n; i++)
    {
        if (m[i] > 0)
        {
            m[i]--;
            bfs(s + (char)i);
            m[i]++;
        }
    }
}

int main()
{
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 'a'; i < 'a' + n; i++)
        {
            m[i] = 1;
        }
        bfs("");
    }
}