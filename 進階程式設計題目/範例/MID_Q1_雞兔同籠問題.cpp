#include <bits/stdc++.h>
using namespace std;

int main()
{
    int total, feet;

    for (int i = 0; i < 5; i++)
    {
        cin >> total >> feet;

        // 設雞的數量為 x，兔子的數量為 y
        // x + y = total
        // 2*x + 4*y = feet
        // 解得：x = 2*total - feet/2, y = feet/2 - total

        if (feet % 2 != 0 || feet < 2 * total || feet > 4 * total)
        {
            cout << "no solution" << endl;
        }
        else
        {
            int rabbits = (feet - 2 * total) / 2;
            int chickens = total - rabbits;

            if (chickens >= 0 && rabbits >= 0)
            {
                cout << chickens << " " << rabbits << endl;
            }
            else
            {
                cout << "no solution" << endl;
            }
        }
    }

    return 0;
}
