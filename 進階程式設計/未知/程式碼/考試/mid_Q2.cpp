#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    while (1)
    {
        int input;
        cin >> input;
        if (input == -1)
            break;
        v.push_back(input);
    }
    sort(v.begin(), v.end());
    cout.precision(1);
    cout << fixed;
    if (v.size() % 2 == 0)
        cout << (v[v.size() / 2 - 1] + v[v.size() / 2]) / 2.0 << endl;
    else
        cout << (double)v[v.size() / 2] << endl;

    int arr[v.size()][2];
    for (int i = 0; i < v.size(); i++)
    {
        arr[i][0] = 0;
        arr[i][1] = 0;
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i] == 0)
            {
                arr[v.size() - 1][1]++;
                break;
            }
            if (v[i] == arr[j][0])
            {
                arr[j][1]++;
                break;
            }
            else if (arr[j][0] == 0)
            {
                arr[j][0] = v[i];
                arr[j][1]++;
                break;
            }
        }
    }
    int count = 0, max_index = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (arr[i][1] > count)
            count = arr[i][1];
        if (arr[i][1] == count)
            max_index = i;
    }
    if (count != 1)
        for (int i = 0; i <= max_index; i++)
        {
            if (arr[i][1] == count)
            {
                cout << arr[i][0] << " ";
            }
        }
    else
        cout << "null " << endl;
}