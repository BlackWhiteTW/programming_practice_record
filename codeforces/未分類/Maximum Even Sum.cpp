#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a, b , ans = -1;
        cin >> a >> b;
        for (long long j = 1; j * j <= b; ++j) {
            if (b % j == 0) {
                long long k1 = j , k2 = b / j;
                long long ta = a * k1, tb = b / k1;
                if ((ta + tb) % 2 == 0) ans = max(ans, ta + tb);
                if (k1 != k2) {
                    ta = a * k2, tb = b / k2;
                    if ((ta + tb) % 2 == 0) ans = max(ans, ta + tb);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}