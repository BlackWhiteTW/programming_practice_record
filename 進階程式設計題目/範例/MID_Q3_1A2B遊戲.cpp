#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        string answer, guess;
        cin >> answer >> guess;

        int A = 0, B = 0;

        // 計算 A（數字和位置均相符）
        for (int j = 0; j < 4; j++)
        {
            if (answer[j] == guess[j])
            {
                A++;
            }
        }

        // 計算 B（數字相同但位置不符）
        for (int j = 0; j < 4; j++)
        {
            if (answer[j] != guess[j])
            {
                // 檢查 guess[j] 是否在 answer 中的其他位置
                for (int k = 0; k < 4; k++)
                {
                    if (k != j && answer[k] == guess[j] && answer[k] != guess[k])
                    {
                        B++;
                        break;
                    }
                }
            }
        }

        cout << A << "A" << B << "B" << endl;
    }

    return 0;
}
