#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> nums(10);
    for (int i = 0; i < 10; i++)
    {
        cin >> nums[i];
    }

    int oddSum = 0, evenSum = 0;
    for (int num : nums)
    {
        if (num % 2 == 0)
        {
            evenSum += num;
        }
        else
        {
            oddSum += num;
        }
    }

    cout << oddSum - evenSum << endl;

    return 0;
}
