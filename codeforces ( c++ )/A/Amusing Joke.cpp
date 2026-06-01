#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a[3];
    for (int i = 0; i < 3; i++)
        cin >> a[i];
    int list1[26] = {0}, list2[26] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < a[i].size(); j++)
        {
            if (i != 2)
                list1[a[i][j] - 'A']++;
            else
                list2[a[i][j] - 'A']++;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        if (list1[i] != list2[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}