#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;

    stack<int> st;
    const int MAX_SIZE = 100;

    for (int i = 0; i < k; i++)
    {
        int m, n;
        cin >> m >> n;

        if (m == 1)
        {
            // Pop: 移除堆疊區頂端整數
            if (!st.empty())
            {
                st.pop();
            }
        }
        else if (m == 2)
        {
            // Print: 印出堆疊區頂端整數
            if (st.empty())
            {
                cout << "null" << endl;
            }
            else
            {
                cout << st.top() << endl;
            }
        }
        else if (m == 3)
        {
            // Push: 插入資料於堆疊區
            if (st.size() < MAX_SIZE)
            {
                st.push(n);
            }
        }
    }

    return 0;
}
