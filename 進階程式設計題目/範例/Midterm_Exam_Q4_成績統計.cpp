#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    map<int, int> scoreCount;

    for (int i = 0; i < k; i++)
    {
        int score;
        cin >> score;
        scoreCount[score]++;
    }

    // 按分數由低至高輸出
    for (auto &p : scoreCount)
    {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}
