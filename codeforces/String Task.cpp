#include <bits/stdc++.h>

using namespace std;

int main()
{
    string str;
    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    for ( char c : str )
    {
        if ( c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i' )
            continue;
        cout << '.' << c;
    }

    return 0;
}