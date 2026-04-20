#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        string input_a, input_b;
        cin >> input_a >> input_b;
        int a = 0, b = 0;
        for (int i = 0; i < 4; i++)
        {
            if (input_a[i] == input_b[i])
            {
                a++;
            }
            else
            {
                for (int j = 0; j < 4; j++)
                {
                    if (input_a[i] == input_b[j])
                    {
                        b++;
                        break;
                    }
                }
            }
        }
        cout << a << "A" << b << "B" << endl;
    }
}