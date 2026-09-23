#include <bits/stdc++.h>

using namespace std;

太棒了！這就是我們所說的「模組化」與「工程化」的最終結晶。

我已經將你寫好的六個核心轉換函式完美整合在一起。為了讓程式碼更乾淨、更好維護，我把「中轉後」的核心邏輯抽出來變成一個共用的 infixToPostfixCore 函式，這樣你的「中轉前」就可以直接呼叫它，完美實現「反轉法」的精髓。

    以下是完整的「全能運算式轉換器」 C++ 程式碼：

        C++
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <sstream>
#include <algorithm>

    using namespace std;

// === 共用工具函式 ===

// 判斷是否為運算子
bool isOperator(string t)
{
    return (t == "+" || t == "-" || t == "*" || t == "/");
}

// 取得運算子優先權
int getP(string s)
{
    if (s == "*" || s == "/")
        return 2;
    if (s == "+" || s == "-")
        return 1;
    return 0;
}

// 核心：中轉後邏輯 (給中轉後與中轉前共用)
string infixToPostfixCore(vector<string> tokens)
{
    stack<string> s;
    vector<string> result;

    for (const string &token : tokens)
    {
        if (isdigit(token[0]))
        {
            result.push_back(token);
        }
        else if (token == "(")
        {
            s.push(token);
        }
        else if (token == ")")
        {
            while (!s.empty() && s.top() != "(")
            {
                result.push_back(s.top());
                s.pop();
            }
            if (!s.empty())
                s.pop(); // 彈出 "("
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
    for (int i = 0; i < result.size(); i++)
    {
        res += result[i] + (i == result.size() - 1 ? "" : " ");
    }
    return res;
}

// === 1. 中轉後 (Infix to Postfix) ===
string infixToPostfix(string line)
{
    stringstream ss(line);
    string token;
    vector<string> tokens;
    while (ss >> token)
        tokens.push_back(token);

    return infixToPostfixCore(tokens);
}

// === 2. 中轉前 (Infix to Prefix) ===
string infixToPrefix(string line)
{
    stringstream ss(line);
    string token;
    vector<string> tokens;
    while (ss >> token)
        tokens.push_back(token);

    // A. 反轉
    reverse(tokens.begin(), tokens.end());

    // B. 括號互換
    for (auto &t : tokens)
    {
        if (t == "(")
            t = ")";
        else if (t == ")")
            t = "(";
    }

    // C. 轉後置
    string res = infixToPostfixCore(tokens);

    // D. 結果再次反轉
    stringstream res_ss(res);
    vector<string> final_tokens;
    while (res_ss >> token)
        final_tokens.push_back(token);
    reverse(final_tokens.begin(), final_tokens.end());

    string final_res = "";
    for (int i = 0; i < final_tokens.size(); i++)
    {
        final_res += final_tokens[i] + (i == final_tokens.size() - 1 ? "" : " ");
    }
    return final_res;
}

// === 3. 前轉後 (Prefix to Postfix) ===
string prefixToPostfix(string prefix)
{
    stack<string> s;
    stringstream ss(prefix);
    string token;
    vector<string> tokens;

    while (ss >> token)
        tokens.push_back(token);

    // 由右向左掃描
    for (int i = tokens.size() - 1; i >= 0; i--)
    {
        string t = tokens[i];
        if (isOperator(t))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push(op1 + " " + op2 + " " + t);
        }
        else
        {
            s.push(t);
        }
    }
    return s.empty() ? "" : s.top();
}

// === 4. 後轉前 (Postfix to Prefix) ===
string postfixToPrefix(string postfix)
{
    stack<string> s;
    stringstream ss(postfix);
    string token;

    // 由左向右掃描
    while (ss >> token)
    {
        if (isOperator(token))
        {
            string op2 = s.top();
            s.pop();
            string op1 = s.top();
            s.pop();
            s.push(token + " " + op1 + " " + op2);
        }
        else
        {
            s.push(token);
        }
    }
    return s.empty() ? "" : s.top();
}

// === 5. 前轉中 (Prefix to Infix) ===
string prefixToInfix(string prefix)
{
    stack<string> s;
    stringstream ss(prefix);
    string token;
    vector<string> tokens;

    while (ss >> token)
        tokens.push_back(token);

    // 由右向左掃描
    for (int i = tokens.size() - 1; i >= 0; i--)
    {
        string t = tokens[i];
        if (isOperator(t))
        {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            s.push("( " + op1 + " " + t + " " + op2 + " )");
        }
        else
        {
            s.push(t);
        }
    }
    return s.empty() ? "" : s.top();
}

// === 6. 後轉中 (Postfix to Infix) ===
string postfixToInfix(string postfix)
{
    stack<string> s;
    stringstream ss(postfix);
    string token;

    // 由左向右掃描
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
            s.push("( " + op1 + " " + token + " " + op2 + " )");
        }
        else
        {
            s.push(token);
        }
    }
    return s.empty() ? "" : s.top();
}

// === 主程式 ===
int main()
{
    int k;
    if (!(cin >> k))
        return 0;

    while (k--)
    {
        int n;
        cin >> n;

        string input;
        getline(cin, input); // 吃掉讀取 n 之後留下的換行符號
        getline(cin, input); // 讀取實際的算式字串

        switch (n)
        {
        case 1:
            cout << "中轉後: " << infixToPostfix(input) << endl;
            break;
        case 2:
            cout << "中轉前: " << infixToPrefix(input) << endl;
            break;
        case 3:
            cout << "前轉後: " << prefixToPostfix(input) << endl;
            break;
        case 4:
            cout << "後轉前: " << postfixToPrefix(input) << endl;
            break;
        case 5:
            cout << "前轉中: " << prefixToInfix(input) << endl;
            break;
        case 6:
            cout << "後轉中: " << postfixToInfix(input) << endl;
            break;
        default:
            cout << "無效的選項！請輸入 1 到 6 之間的數字。" << endl;
            break;
        }
    }
    return 0;
}