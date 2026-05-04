#include <bits/stdc++.h>
using namespace std;

static vector<vector<long long>> parseMatrix(const string &line)
{
    vector<vector<long long>> matrix;
    regex rowPattern(R"(\{([^\{\}]*)\})");
    for (auto it = sregex_iterator(line.begin(), line.end(), rowPattern); it != sregex_iterator(); ++it)
    {
        vector<long long> row;
        string rowText = (*it)[1].str();
        string token;
        stringstream ss(rowText);
        while (getline(ss, token, ','))
            if (!token.empty())
                row.push_back(stoll(token));
        if (!row.empty())
            matrix.push_back(row);
    }
    return matrix;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string aLine, bLine;
    getline(cin, aLine);
    getline(cin, bLine);
    auto a = parseMatrix(aLine);
    auto b = parseMatrix(bLine);

    int m = (int)a.size(), n = (int)a[0].size(), p = (int)b[0].size();
    cout << "{";
    for (int i = 0; i < m; ++i)
    {
        if (i)
            cout << ",";
        cout << "{";
        for (int j = 0; j < p; ++j)
        {
            if (j)
                cout << ",";
            long long sum = 0;
            for (int k = 0; k < n; ++k)
                sum += a[i][k] * b[k][j];
            cout << sum;
        }
        cout << "}";
    }
    cout << "}" << '\n';
    return 0;
}