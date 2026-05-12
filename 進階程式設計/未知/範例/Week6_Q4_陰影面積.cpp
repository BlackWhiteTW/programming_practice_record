#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        double a;
        cin >> a;

        // Shaded area = (πa²)/4 - (a²)/2 = a²(π/4 - 1/2) = a²(π - 2)/4
        // Or it could be the area of the square minus quarter circle
        // Based on the example: a=2.77 -> 3.84
        // Square area = 2.77² = 7.6729
        // If shaded is half the square minus quarter circle:
        // But let me calculate: a²(π - 2)/4 = 2.77²(3.14159-2)/4 ≈ 7.6729 * 0.28540 ≈ 2.19
        // That doesn't match. Let me try: a²/2 * (π - 2)/2 ≈ doesn't work either
        // Let me think: area = a² * (π - 2) / 4 = 7.6729 * 1.14159/4 = 2.19... no
        // Wait: if it's quarter circle minus triangle: (π*a²/4 - a²/2) won't work
        // Let me try: a²(π/2 - 1) or other combinations
        // 2.77² * (π/2 - 1) = 7.6729 * 0.5708 = 4.38... closer!
        // Let me try a²(π - 1)/4 = 7.6729 * 2.14159/4 = 4.11...
        // Actually: a² * π/4 - a²/2 = 7.6729(0.7854 - 0.5) = 7.6729 * 0.2854 = 2.19
        // Let me try another: a²(π - 2) doesn't seem right either
        // What if it's just a²(π/4 - 1/2 + 1) = a²(π/4 + 1/2)? Let's check: 7.6729 * (0.7854 + 0.5) = 9.76...
        // Or: a²/(π - 2) won't work
        // Actually looking at the answer 3.84, and a=2.77, if we multiply: 3.84/7.6729 ≈ 0.5
        // So maybe shaded area = a²/2 * something? Or a²(π - 2)/2 * π something
        // Let me try area = a² * (π - 2) / 2 = 7.6729 * 1.14159/2 = 4.38
        // Hmm, very close! Let me check the second example
        // a=11.99: 11.99² = 143.76, 143.76 * 1.14159/2 = 82.07... but answer is 71.88
        // Let me try a²(π - 2) / π ≈ 7.6729 * 0.3634 = 2.79... no
        // Wait: a²/2 - a²(4-π)/4π? This is getting complex
        // Looking at pattern: 3.84 vs 71.88, if a goes from 2.77 to 11.99 (4.33x)
        // Area should go 4.33² = 18.75x, 71.88/3.84 = 18.71... MATCHES!
        // So the formula is consistent. Let me figure out what it is.
        // 3.84 = 2.77² * x => x = 3.84/7.6729 = 0.5
        // So the formula is simply a²/2 !

        double area = a * a / 2.0;
        cout << fixed << setprecision(2) << area << "\n";
    }

    return 0;
}
