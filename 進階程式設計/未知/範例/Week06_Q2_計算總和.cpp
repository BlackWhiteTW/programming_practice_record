#include <bits/stdc++.h>
using namespace std;

int main()
{
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    stringstream s1(line1), s2(line2);
    vector<long long> a, b;
    long long x;
    while (s1 >> x)
        a.push_back(x);
    while (s2 >> x)
        b.push_back(x);

    long long sum = 0;
    for (size_t i = 0; i < a.size(); ++i)
        sum += a[i] * b[b.size() - 1 - i];
    cout << sum << '\n';
    return 0;
}