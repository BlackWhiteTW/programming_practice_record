#include <bits/stdc++.h>

using namespace std;

bool found = false;

void generate(int num, int n) {
    if (num > n) return;
    if (num > 0 && n % num == 0) found = true;
    if (found) return;
    generate(num * 10 + 4, n);
    generate(num * 10 + 7, n);
}

int main() {
    int n;
    cin >> n;
    generate(0, n);
    cout << (found ? "YES" : "NO");
    return 0;
}
