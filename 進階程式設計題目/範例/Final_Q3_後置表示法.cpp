#include <bits/stdc++.h>
using namespace std;

int precedence(string op)
{
    if (op == "+" || op == "-")
        return 1;
    if (op == "*" || op == "/")
        return 2;
    return 0;
}

int main()
{
    int k;
    cin >> k;
    cin.ignore();

    for (int i = 0; i < k; i++)
    {
        string line;
        getline(cin, line);

        vector<string> tokens;
        stringstream ss(line);
        string token;
        while (ss >> token)
        {
            tokens.push_back(token);
        }

        // 使用堆疊進行中置轉後置
        stack<string> opStack;
        vector<string> result;

        for (const string &t : tokens)
        {
            if (t == "(")
            {
                opStack.push(t);
            }
            else if (t == ")")
            {
                while (!opStack.empty() && opStack.top() != "(")
                {
                    result.push_back(opStack.top());
                    opStack.pop();
                }
                if (!opStack.empty())
                {
                    opStack.pop(); // 移除 "("
                }
            }
            else if (t == "+" || t == "-" || t == "*" || t == "/")
            {
                while (!opStack.empty() && opStack.top() != "(" &&
                       precedence(opStack.top()) >= precedence(t))
                {
                    result.push_back(opStack.top());
                    opStack.pop();
                }
                opStack.push(t);
            }
            else
            {
                // 數字
                result.push_back(t);
            }
        }

        while (!opStack.empty())
        {
            result.push_back(opStack.top());
            opStack.pop();
        }

        // 輸出結果
        for (int j = 0; j < result.size(); j++)
        {
            if (j > 0)
                cout << " ";
            cout << result[j];
        }
        cout << endl;
    }

    return 0;
}
