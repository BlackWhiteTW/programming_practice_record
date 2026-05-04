#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long num;
    while (cin >> num && num != -1)
    {
        string s = to_string(num);
        reverse(s.begin(), s.end());

        // Convert back to integer to remove leading zeros, then output
        long long reversed = stoll(s);
        cout << reversed << "\n";
    }

    return 0;
}
