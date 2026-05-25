#include <bits/stdc++.h>

using namespace std;

void sort(int arr[][2], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j][0] > arr[j + 1][0])
            {
                swap(arr[j][0], arr[j + 1][0]);
                swap(arr[j][1], arr[j + 1][1]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n], ans[n][2];
    for (int i = 0; i < n; i++)
    {
        ans[i][0] = -1;
        ans[i][1] = 0;
    }
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        arr[i] = stoi(s.substr(3, 2));
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (ans[j][0] == -1)
            {
                ans[j][0] = arr[i];
                ans[j][1] = 1;
                break;
            }
            else if (ans[j][0] == arr[i])
            {
                ans[j][1]++;
                break;
            }
        }
    }
    sort(ans, n);
    for (int i = 0; i < n; i++)
    {
        if (ans[i][0] != -1)
            cout << ans[i][0] << " " << ans[i][1] << endl;
    }
}