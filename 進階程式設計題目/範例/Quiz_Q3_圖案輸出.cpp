#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        int m, n;
        char comma;
        cin >> m >> comma >> n;

        if (m == 1)
        {
            // 模式 1: 等腰三角形
            for (int j = 1; j <= n; j++)
            {
                for (int p = 0; p < j; p++)
                {
                    cout << "$";
                    if (p < j - 1)
                        cout << " ";
                }
                cout << endl;
            }
        }
        else if (m == 2)
        {
            // 模式 2: 三角形，每行相隔一格
            for (int j = 1; j <= n; j++)
            {
                for (int p = 0; p < j; p++)
                {
                    cout << "$";
                    if (p < j - 1)
                        cout << " ";
                }
                cout << endl;
            }
        }
        else if (m == 3)
        {
            // 模式 3: 梯形
            for (int j = 1; j <= n; j++)
            {
                for (int p = 0; p < j + 1; p++)
                {
                    cout << "$";
                    if (p < j)
                        cout << " ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}
