#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;
    int a, b;
    char c;
    int map[x][y] = {0};
    while (cin >> a >> b >> c)
    {
        string s;
        cin >> s;
        int dir = 0;
        char list[] = {'N', 'E', 'S', 'W'};
        for (int i = 0; i < 4; i++)
            if (list[i] == c)
                dir = i;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'R')
                dir = (dir + 1) % 4;
            else if (s[i] == 'L')
                dir = (dir + 3) % 4;
            else
            {
                int dx = 0, dy = 0;
                switch (dir)
                {
                case 0:
                    dy = 1;
                    break;
                case 1:
                    dx = 1;
                    break;
                case 2:
                    dy = -1;
                    break;
                case 3:
                    dx = -1;
                    break;
                }
                a += dx;
                b += dy;
                if (a < 0 || a > x || b < 0 || b > y)
                {
                    if (map[a - dx][b - dy])
                        a -= dx, b -= dy;
                    else
                    {
                        cout << a - dx << " " << b - dy << " " << list[dir] << " LOST" << endl;
                        map[a - dx][b - dy] = 1;
                        break;
                    }
                }
            }
        }
        if (a >= 0 && a <= x && b >= 0 && b <= y)
            cout << a << " " << b << " " << list[dir] << endl;
    }
}