#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<long long> nums;
    long long x;
    while (cin >> x && x != -1)
        nums.push_back(x);
    long long g = nums[0];
    for (size_t i = 1; i < nums.size(); ++i)
        g = gcd(g, nums[i]);
    cout << g << '\n';
    return 0;
}