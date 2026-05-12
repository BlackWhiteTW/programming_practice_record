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

    // 計算平均數
    double sum = 0;
    for (int g : grades)
    {
        sum += g;
    }
    double average = sum / grades.size();

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
    average = round(average * 10) / 10.0;
    median = round(median * 10) / 10.0;

    cout << fixed << setprecision(1) << average << " " << median << endl;

    return 0;
}
