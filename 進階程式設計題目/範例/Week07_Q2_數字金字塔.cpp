#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h;
    cin >> h;
    for (int row = 1; row <= h; ++row)
    {
        cout << string((h - row) * 4, '+');
        vector<int> seq;
        for (int x = row; x <= 2 * row - 1; ++x)
            seq.push_back(x);
        for (int x = 2 * row - 2; x >= row; --x)
            seq.push_back(x);
        for (size_t i = 0; i < seq.size(); ++i)
        {
            if (i)
                cout << "+++";
            cout << seq[i];
        }
        cout << '\n';
    }
    return 0;
}