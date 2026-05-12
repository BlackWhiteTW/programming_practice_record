#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    if (!(cin >> k))
        return 0;

    const int MAX_SIZE = 100;
    vector<int> st;
    st.reserve(MAX_SIZE);

    for (int i = 0; i < k; i++)
    {
        int m, n;
        cin >> m >> n;

        if (m == 1)
        {
            if (!st.empty())
                st.pop_back();
        }
        else if (m == 2)
        {
            if (st.empty())
                cout << "null\n";
            else
                cout << st.back() << '\n';
        }
        else
        {
            if ((int)st.size() < MAX_SIZE)
                st.push_back(n);
        }
    }

    return 0;
}
