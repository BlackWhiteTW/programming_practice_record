#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    map<int, int> oddFreq, evenFreq;

    for (int i = 0; i < k; i++)
    {
        int num;
        cin >> num;

        if (num % 2 == 0)
        {
            evenFreq[num]++;
        }
        else
        {
            oddFreq[num]++;
        }
    }

    // 找出現最多次的奇數
    int A = 0, maxOddCount = 0;
    for (auto &p : oddFreq)
    {
        if (p.second > maxOddCount || (p.second == maxOddCount && p.first > A))
        {
            A = p.first;
            maxOddCount = p.second;
        }
    }

    // 找出現最多次的偶數
    int B = 0, maxEvenCount = 0;
    for (auto &p : evenFreq)
    {
        if (p.second > maxEvenCount || (p.second == maxEvenCount && p.first > B))
        {
            B = p.first;
            maxEvenCount = p.second;
        }
    }

    cout << abs(A - B) << endl;

    return 0;
}
