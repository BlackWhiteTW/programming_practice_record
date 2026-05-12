#include <bits/stdc++.h>

#define PI 3.14

using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int input;
        cin >> input;
        float temp = pow(input / 2.0, 2) * PI / 2 + pow(input / 2.0, 2);
        float output = pow(input, 2) / 4 * PI - temp;
        cout.precision(2);
        cout << fixed << output << endl;
    }
}