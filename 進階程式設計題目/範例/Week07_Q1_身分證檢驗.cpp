#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, int> mp = {
        {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}, {'G', 16}, {'H', 17}, {'I', 34}, {'J', 18}, {'K', 19}, {'L', 20}, {'M', 21}, {'N', 22}, {'O', 35}, {'P', 23}, {'Q', 24}, {'R', 25}, {'S', 26}, {'T', 27}, {'U', 28}, {'V', 29}, {'W', 32}, {'X', 30}, {'Y', 31}, {'Z', 33}};
    string id;
    while (cin >> id && id != "-1")
    {
        int code = mp[id[0]];
        int total = code / 10 + (code % 10) * 9;
        for (int i = 1; i <= 8; ++i)
            total += (id[i] - '0') * (9 - i);
        total += id[9] - '0';
        cout << (total % 10 == 0 ? "Real" : "Fake") << '\n';
    }
    return 0;
}