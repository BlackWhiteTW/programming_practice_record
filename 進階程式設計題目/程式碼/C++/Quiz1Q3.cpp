#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int n, m;
        char ch;
        cin >> m >> ch >> n;
        switch (m)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j <= i; j++)
                    cout << "$ ";
                cout << endl;
            }
            break;
        case 2:
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                    cout << "  ";
                for (int j = 0; j < i + 1; j++)
                    cout << "$ ";
                cout << endl;
            }
            break;
        case 3:
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                    cout << "  ";
                for (int j = 0; j < 2 * i + 1; j++)
                    cout << "$ ";
                cout << endl;
            }
            break;
        }
    }
}