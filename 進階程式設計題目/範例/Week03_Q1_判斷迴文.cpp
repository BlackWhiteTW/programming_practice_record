#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int n)
{
    string s = to_string(n);
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return s == reversed;
}

int main()
{
    int n;
    while (cin >> n && n != -1)
    {
        if (isPalindrome(n))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
