#include <bits/stdc++.h>

using namespace std;

struct node
{
    int a = 0, b = 0;
};

node fib(int a, int b, int n, int count)
{
    if (a <= n && b > n)
        return {a, count};
    else
        return fib(b, a + b, n, count + 1);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;
        cout << in << " = ";
        node ans = fib(1, 1, in, 0);
        int tip = ans.b, temp = 0;
        while (in != 0)
        {
            ans = fib(1, 1, in, 0);
            temp = ans.b;
            while (tip > temp + 1)
            {
                cout << "0";
                tip--;
            }
            tip = temp;
            cout << "1";
            in -= ans.a;
        }
        while (tip > 1)
        {
            cout << "0";
            tip--;
        }
        cout << " (fib)" << endl;
    }
}