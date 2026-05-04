#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.ignore();
    string s;
    getline(cin, s);

    string result = "";

    for (int i = s.length() - 1; i >= 0; i--)
    {
        char c = s[i];
        if (c >= 'A' && c <= 'Z')
        {
            result += tolower(c);
        }
        else if (c >= 'a' && c <= 'z')
        {
            result += toupper(c);
        }
    }

    cout << result << endl;

    return 0;
}
