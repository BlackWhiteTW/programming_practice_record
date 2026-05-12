#include <bits/stdc++.h>
using namespace std;

static int d2(int x) { return x / 100; }
static int d1(int x) { return (x / 10) % 10; }
static int d0(int x) { return x % 10; }

int main()
{
    int k;
    cin >> k;
    string line;
    getline(cin, line);
    getline(cin, line);
    for (char &c : line)
        if (c == ',')
            c = ' ';
    stringstream ss(line);
    vector<int> nums;
    int x;
    while (ss >> x)
        nums.push_back(x);
    sort(nums.begin(), nums.end(), [](int a, int b)
         {
        if (d2(a) != d2(b)) return d2(a) < d2(b);
        if (d1(a) != d1(b)) return d1(a) > d1(b);
        if ((d0(a) % 2) != (d0(b) % 2)) return d0(a) % 2 == 0;
        return d0(a) < d0(b); });
    for (size_t i = 0; i < nums.size(); ++i)
    {
        if (i)
            cout << ',';
        cout << nums[i];
    }
    cout << '\n';
    return 0;
}