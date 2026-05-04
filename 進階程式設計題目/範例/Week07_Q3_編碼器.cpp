#include <bits/stdc++.h>
using namespace std;

static char shiftChar(char c, int s)
{
    if ('A' <= c && c <= 'Z')
    {
        int v = (c - 'A' + s) % 26;
        if (v < 0)
            v += 26;
        return char('A' + v);
    }
    int v = (c - 'a' + s) % 26;
    if (v < 0)
        v += 26;
    return char('a' + v);
}

int main()
{
    int m, s;
    cin >> m >> s;
    string line;
    getline(cin, line);
    for (int i = 0; i < m; ++i)
    {
        getline(cin, line);
        for (char &c : line)
            c = shiftChar(c, s);
        cout << line << '\n';
    }
    return 0;
}