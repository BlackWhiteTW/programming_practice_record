#include <bits/stdc++.h>

using namespace std;

bool isOperator(string t)
{
    return (t == "+" || t == "-" || t == "*" || t == "/");
}

string postfixToPrefix(string postfix)
{
    stack<string> s;
    stringstream ss(postfix);
    string token;

    while (ss >> token)
    {
        if (isOperator(token))
        {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();

            string combined = token + " " + op1 + " " + op2;
            s.push(combined);
        }
        else
        {
            s.push(token);
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
        if (getline(cin, input) && !input.empty())
        {
            cout << postfixToPrefix(input) << endl;
        }
    }
    return 0;
}