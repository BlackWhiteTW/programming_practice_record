#include <bits/stdc++.h>

using namespace std;

int n3(int n)
{
    int l = 0;
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;
        l++;
    }
    return l;
}

int main()
{
    int a, b;
    while (cin >> a >> b)
    {
        int start = a, end = b;
        if (a > b)
            swap(start, end);
        int max = 0;
        for (int i = start; i <= end; i++)
            if (n3(i) > max)
                max = n3(i);
        cout << a << " " << b << " " << max + 1 << endl;
    }
}