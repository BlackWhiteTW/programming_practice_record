#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> nums;
    int x;

    while (cin >> x && x != -1)
    {
        nums.push_back(x);
    }

    // Calculate arithmetic mean
    double sum = 0;
    for (int num : nums)
    {
        sum += num;
    }
    double mean = sum / nums.size();

    // Calculate median
    sort(nums.begin(), nums.end());
    double median;
    if (nums.size() % 2 == 1)
    {
        median = nums[nums.size() / 2];
    }
    else
    {
        median = (nums[nums.size() / 2 - 1] + nums[nums.size() / 2]) / 2.0;
    }

    // Output with 1 decimal place
    cout << fixed << setprecision(1) << mean << " " << median << "\n";

    return 0;
}
