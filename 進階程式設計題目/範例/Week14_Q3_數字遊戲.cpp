#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using boost::multiprecision::cpp_int;

static cpp_int toBig(const string &s)
{
    cpp_int v = 0;
    for (char c : s)
        v = v * 10 + (c - '0');
    return v;
}

int main()
{
    string a, b, pool;
    getline(cin, a);
    getline(cin, b);
    getline(cin, pool);

    vector<char> digits;
    for (char c : pool)
        if (isdigit((unsigned char)c))
            digits.push_back(c);
    sort(digits.begin(), digits.end(), greater<char>());

    struct Pos
    {
        int idx;
        int box;
    };
    vector<Pos> pos;
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] == '?')
            pos.push_back({i, 0});
    for (int i = 0; i < (int)b.size(); ++i)
        if (b[i] == '?')
            pos.push_back({i, 1});
    sort(pos.begin(), pos.end(), [&](const Pos &x, const Pos &y)
         {
        if (x.idx != y.idx) return x.idx < y.idx;
        return x.box < y.box; });

    auto fillBox = [&](string s, int box)
    {
        for (auto &p : pos)
        {
            if (p.box == box)
            {
                s[p.idx] = digits.back();
                digits.pop_back();
            }
        }
        return s;
    };

    // To maximize total sum, assign largest digits to most significant ? positions across both boxes.
    vector<Pos> allPos = pos;
    sort(allPos.begin(), allPos.end(), [](const Pos &x, const Pos &y)
         { return x.idx < y.idx; });
    string aa = a, bb = b;
    for (auto &p : allPos)
    {
        char d = digits.front();
        digits.erase(digits.begin());
        if (p.box == 0)
            aa[p.idx] = d;
        else
            bb[p.idx] = d;
    }

    cout << (toBig(aa) + toBig(bb)) << '\n';
    return 0;
}