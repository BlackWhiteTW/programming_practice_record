#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        string str;
        cin >> str;
        int n = str.size();
        stack<char> s;
        for (int i = 0; i < n; i++)
        {
            char c = str[i];
            if (c == '(' || c == '[' || c == '{')
            {
                s.push(c);
            }
            else
            {
                if (s.empty())
                {
                    s.push(c);
                    break;
                }
                char top = s.top();
                if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{'))
                {
                    s.pop();
                }
            }
        }
        if (!s.empty())
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
}