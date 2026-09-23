#include <bits/stdc++.h>

using namespace std;

string prefixToInfix(string prefix)
{
    stack<string> s;
    stringstream ss(prefix);
    string token;
    vector<string> tokens;

    while (ss >> token)
        tokens.push_back(token);

    for (int i = tokens.size() - 1; i >= 0; i--)
    {
        string t = tokens[i];
        if (t == "+" || t == "-" || t == "*" || t == "/")
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            string combined = "( " + op1 + " " + t + " " + op2 + " )";
            s.push(combined);
        }
        else
        {
            s.push(t);
        }
    }
    return s.top();
}

int main()
{
    int k;
    cin >> k;
    string input;
    getline(cin, input);
    while (k--)
    {
        getline(cin, input);
        cout << prefixToInfix(input) << endl;
    }
    return 0;
}