#include <bits/stdc++.h>

using namespace std;

void set_zero(int student[][2], int len)
{
    for (int i = 0; i < len; i++)
    {
        student[i][0] = 0;
        student[i][1] = 0;
    }
    return;
}

void check(int student[][2], int input, int *len)
{
    for (int i = 0; i < *len; i++)
    {
        if (student[i][0] == input)
        {
            student[i][1]++;
            return;
        }
    }
    student[*len][0] = input;
    student[*len][1]++;
    (*len)++;
    return;
}

int main()
{
    int k, index = 0;
    cin >> k;
    int student[k][2];
    set_zero(student, k);
    for (int i = 0; i < k; i++)
    {
        int input;
        cin >> input;
        check(student, input, &index);
    }

    for (int i = 0; i < index - 1; i++)
    {
        for (int j = i + 1; j < index; j++)
        {
            if (student[j][0] < student[i][0])
            {
                swap(student[j][0], student[i][0]);
                swap(student[j][1], student[i][1]);
            }
        }
    }

    for (int i = 0; i < index; i++)
    {
        cout << student[i][0] << " " << student[i][1] << endl;
    }
}