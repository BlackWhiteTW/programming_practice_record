#include <bits/stdc++.h>

using namespace std;

int getP(string s)
{
    if (s == "*" || s == "/")
        return 2;
    if (s == "+" || s == "-")
        return 1;
    return 0;
}

int main()
{
    int k;
    cin >> k;
    string line;
    getline(cin, line);

    while (k--)
    {
        getline(cin, line);
        stringstream ss(line);
        string token;

        stack<string> s;
        vector<string> result;

        while (ss >> token)
        {
            if (isdigit(token[0]))
                result.push_back(token);
            else if (token == "(")
                s.push(token);
            else if (token == ")")
            {
                while (!s.empty() && s.top() != "(")
                {
                    result.push_back(s.top());
                    s.pop();
                }
                s.pop();
            }
            else
            {
                while (!s.empty() && getP(s.top()) >= getP(token))
                {
                    result.push_back(s.top());
                    s.pop();
                }
                s.push(token);
            }
        }
        while (!s.empty())
        {
            result.push_back(s.top());
            s.pop();
        }
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << (i == result.size() - 1 ? "" : " ");
        cout << endl;
    }
    return 0;
}