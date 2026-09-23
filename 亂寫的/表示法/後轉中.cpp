#include <bits/stdc++.h>

using namespace std;

bool isOperator(string t)
{
    return (t == "+" || t == "-" || t == "*" || t == "/");
}

string postfixToInfix(string postfix)
{
    stack<string> s;
    stringstream ss(postfix);
    string token;

    while (ss >> token)
    {
        if (isOperator(token))
        {
            if (s.size() < 2)
                return "Error";

            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            string combined = "( " + op1 + " " + token + " " + op2 + " )";
            s.push(combined);
        }
        else
        {
            s.push(token);
        }
    }
    return s.empty() ? "" : s.top();
}

int main()
{
    int k;
    cin >> k;
    string input;
    getline(cin, input);

    while (k--)
    {
        if (getline(cin, input) && !input.empty())
        {
            cout << postfixToInfix(input) << endl;
        }
    }
    return 0;
}