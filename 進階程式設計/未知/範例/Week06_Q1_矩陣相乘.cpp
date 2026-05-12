#include <bits/stdc++.h>
using namespace std;

static vector<vector<int>> parseMatrixLine(const string &line)
{
    vector<vector<int>> matrix;
    regex rowPattern(R"(\{([^\{\}]*)\})");
    for (auto it = sregex_iterator(line.begin(), line.end(), rowPattern); it != sregex_iterator(); ++it)
    {
        vector<int> row;
        string rowText = (*it)[1].str();
        string token;
        stringstream ss(rowText);
        while (getline(ss, token, ','))
        {
            if (!token.empty())
                row.push_back(stoi(token));
        }
        if (!row.empty())
            matrix.push_back(row);
    }
    return matrix;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line);
    auto a = parseMatrixLine(line);
    getline(cin, line);
    auto b = parseMatrixLine(line);

    int m = (int)a.size();
    int n = (int)a[0].size();
    int p = (int)b[0].size();

    vector<vector<long long>> c(m, vector<long long>(p, 0));
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < p; ++j)
        {
            long long sum = 0;
            for (int k = 0; k < n; ++k)
                sum += 1LL * a[i][k] * b[k][j];
            c[i][j] = sum;
        }
    }

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
            cout << c[i][j];
        }
        cout << "}";
    }
    cout << "}" << '\n';
    return 0;
}