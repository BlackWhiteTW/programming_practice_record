#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> grades;
    int num;

    while (cin >> num && num != -1)
    {
        grades.push_back(num);
    }

    // 計算中位數
    sort(grades.begin(), grades.end());
    double median;
    if (grades.size() % 2 == 1)
    {
        median = grades[grades.size() / 2];
    }
    else
    {
        median = (grades[grades.size() / 2 - 1] + grades[grades.size() / 2]) / 2.0;
    }

    // 四捨五入到小數點第1位
    median = round(median * 10) / 10.0;

    cout << fixed << setprecision(1) << median << endl;

    // 計算眾數
    map<int, int> freq;
    int maxFreq = 0;
    for (int g : grades)
    {
        freq[g]++;
        maxFreq = max(maxFreq, freq[g]);
    }

    // 如果最大頻度為 1（即每個數字只出現一次），則沒有眾數
    if (maxFreq == 1)
    {
        cout << "null" << endl;
    }
    else
    {
        vector<int> modes;
        for (auto &p : freq)
        {
            if (p.second == maxFreq)
            {
                modes.push_back(p.first);
            }
        }

        for (int i = 0; i < modes.size(); i++)
        {
            if (i > 0)
                cout << " ";
            cout << modes[i];
        }
        cout << endl;
    }

    return 0;
}
