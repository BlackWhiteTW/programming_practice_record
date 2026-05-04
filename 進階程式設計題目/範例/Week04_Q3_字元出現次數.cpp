#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.ignore();
    string s;
    getline(cin, s);

    int uppercase = 0, lowercase = 0, digits = 0, symbols = 0;

    for (char c : s)
    {
        if (c >= 'A' && c <= 'Z')
        {
            uppercase++;
        }
        else if (c >= 'a' && c <= 'z')
        {
            lowercase++;
        }
        else if (c >= '0' && c <= '9')
        {
            digits++;
        }
        else if (c != ' ')
        {
            symbols++;
        }
    }

    cout << uppercase << endl;
    cout << lowercase << endl;
    cout << digits << endl;
    cout << symbols << endl;

    return 0;
}
