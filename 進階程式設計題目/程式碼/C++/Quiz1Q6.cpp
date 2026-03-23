#include <bits/stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        double input;
        cin >> input;
        double output = pow(input, 2) / 2.0;
        cout.precision(2);
        cout << fixed << output << endl;
    }
}