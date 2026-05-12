#include <bits/stdc++.h>
using namespace std;
using u128 = __uint128_t;
using u64 = unsigned long long;

static u64 modMul(u64 a, u64 b, u64 mod) { return (u128)a * b % mod; }

static u64 modPow(u64 a, u64 d, u64 mod)
{
    u64 r = 1;
    while (d)
    {
        if (d & 1)
            r = modMul(r, a, mod);
        a = modMul(a, a, mod);
        d >>= 1;
    }
    return r;
}

static bool isPrime(u64 n)
{
    if (n < 2)
        return false;
    for (u64 p : {2ULL, 3ULL, 5ULL, 7ULL, 11ULL, 13ULL, 17ULL, 19ULL, 23ULL, 29ULL, 31ULL, 37ULL})
    {
        if (n % p == 0)
            return n == p;
    }
    u64 d = n - 1, s = 0;
    while ((d & 1) == 0)
        d >>= 1, ++s;
    for (u64 a : {2ULL, 325ULL, 9375ULL, 28178ULL, 450775ULL, 9780504ULL, 1795265022ULL})
    {
        if (a % n == 0)
            continue;
        u64 x = modPow(a % n, d, n);
        if (x == 1 || x == n - 1)
            continue;
        bool comp = true;
        for (u64 r = 1; r < s; ++r)
        {
            x = modMul(x, x, n);
            if (x == n - 1)
            {
                comp = false;
                break;
            }
        }
        if (comp)
            return false;
    }
    return true;
}

int main()
{
    string s;
    while (cin >> s && s != "-1")
    {
        u64 n = stoull(s);
        cout << (isPrime(n) ? s : string("Not a prime number")) << '\n';
    }
    return 0;
}