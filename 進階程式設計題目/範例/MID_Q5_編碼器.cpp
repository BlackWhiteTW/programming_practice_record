#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;
    cin.ignore();

    for (int i = 0; i < m; i++)
    {
        string content;
        getline(cin, content);

        string offsetStr;
        getline(cin, offsetStr);

        // 解析偏移量
        vector<int> offsets;
        stringstream ss(offsetStr);
        string token;
        while (getline(ss, token, ','))
        {
            offsets.push_back(stoi(token));
        }

        // 編碼
        string result = "";
        for (int j = 0; j < content.length(); j++)
        {
            char ch = content[j];
            int offset = offsets[j];

            if (ch >= 'A' && ch <= 'Z')
            {
                // 大寫字母
                int pos = ch - 'A';
                pos = (pos + offset) % 26;
                if (pos < 0)
                    pos += 26;
                result += (char)('A' + pos);
            }
            else if (ch >= 'a' && ch <= 'z')
            {
                // 小寫字母
                int pos = ch - 'a';
                pos = (pos + offset) % 26;
                if (pos < 0)
                    pos += 26;
                result += (char)('a' + pos);
            }
        }

        cout << result << endl;
    }

    return 0;
}
