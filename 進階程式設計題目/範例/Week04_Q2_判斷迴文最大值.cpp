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
    int k;
    cin >> k;

    int maxPalindrome = -1;

    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;

        if (isPalindrome(num) && num > maxPalindrome)
        {
            maxPalindrome = num;
        }
    }

    if (maxPalindrome == -1)
    {
        cout << "ERROR" << endl;
    }
    else
    {
        cout << maxPalindrome << endl;
    }

    return 0;
}
