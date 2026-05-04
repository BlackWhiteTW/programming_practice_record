#include <bits/stdc++.h>
using namespace std;

int main()
{
    string firstLine, text;
    getline(cin, firstLine);
    getline(cin, text);

    for (char &c : firstLine)
        if (c == ',')
            c = ' ';
    stringstream ss(firstLine);
    long long m, n;
    ss >> m >> n;

    ostringstream ps;
    ps << fixed << setprecision(2) << (log2((double)m) + log2((double)n));
    vector<string> inserts = {to_string(m), to_string(n), ps.str()};

    string result;
    int idx = 0;
    for (size_t i = 0; i < text.size(); ++i)
    {
        if (i + 1 < text.size() && text[i] == '#' && text[i + 1] == '#')
        {
            result += "##" + inserts[idx++];
            ++i;
        }
        else
        {
            result += text[i];
        }
    }
    cout << result << '\n';
    return 0;
}