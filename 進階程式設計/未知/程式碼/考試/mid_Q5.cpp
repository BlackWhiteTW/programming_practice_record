#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m;
    cin >> m;

    while (m--)
    {
        string input;
        cin >> input;
        int str[input.size()];
        for (int i = 0; i < input.size(); i++)
        {
            int in_put;
            char c;
            cin >> in_put;
            if (i < input.size() - 1)
                cin >> c;
            str[i] = in_put;
        }

        for (int i = 0; i < input.size(); i++)
        {
            if (input[i] >= 'a' && input[i] <= 'z')
            {
                cout << (char)((input[i] - 'a' + str[i] + 104) % 26 + 'a');
            }
            else
            {
                cout << (char)((input[i] - 'A' + str[i] + 104) % 26 + 'A');
            }
        }
        cout << endl;
    }
}