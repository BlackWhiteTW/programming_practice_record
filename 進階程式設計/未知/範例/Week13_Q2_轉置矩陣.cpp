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
            if (!token.empty())
                row.push_back(stoi(token));
        if (!row.empty())
            matrix.push_back(row);
    }
    return matrix;
}

int main()
{
    string line;
    getline(cin, line);
    auto a = parseMatrixLine(line);
    int m = (int)a.size(), n = (int)a[0].size();
    cout << "{";
    for (int i = 0; i < n; ++i)
    {
        if (i)
            cout << ",";
        cout << "{";
        for (int j = 0; j < m; ++j)
        {
            if (j)
                cout << ",";
            cout << a[j][i];
        }
        cout << "}";
    }
    cout << "}" << '\n';
    return 0;
}