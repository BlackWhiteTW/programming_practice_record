#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> v;
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int tip;
        cin >> tip;
        switch (tip)
        {
        case 1:
            v.pop_back();
            break;
        case 2:
            if (v.empty())
                cout << "null" << endl;
            else
                cout << v.back() << endl;
            break;
        case 3:
            int x;
            cin >> x;
            v.push_back(x);
            break;
        }
    }
}