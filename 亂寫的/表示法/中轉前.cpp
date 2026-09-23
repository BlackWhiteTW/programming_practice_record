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

string infixToPostfix(vector<string> tokens)
{
    stack<string> s;
    vector<string> result;
    for (const string &token : tokens)
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

    string res = "";
    for (const string &str : result)
        res += str + " ";
    return res;
}

string infixToPrefix(string line)
{
    stringstream ss(line);
    string token;
    vector<string> tokens;
    while (ss >> token)
        tokens.push_back(token);
    reverse(tokens.begin(), tokens.end());
    for (auto &t : tokens)
    {
        if (t == "(")
            t = ")";
        else if (t == ")")
            t = "(";
    }
    string res = infixToPostfix(tokens);
    stringstream res_ss(res);
    vector<string> final_tokens;
    while (res_ss >> token)
        final_tokens.push_back(token);
    reverse(final_tokens.begin(), final_tokens.end());

    string final_res = "";
    for (const string &str : final_tokens)
        final_res += str + " ";
    return final_res;
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
        cout << infixToPrefix(input) << endl;
    }
    return 0;
}