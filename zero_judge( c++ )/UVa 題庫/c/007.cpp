#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    bool b = 1;
    while (getline(cin, str))
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '"')
            {
                if (b)
                {
                    cout << "``";
                    b = 0;
                }
                else
                {
                    cout << "''";
                    b = 1;
                }
            }
            else
                cout << str[i];
        }
        cout << endl;
    }
}