#include <stdio.h>

long long steps = 0;

// 河內塔：把 n 個盤從 f 移到 t，使用 a 作為輔助
void hanoi_std(int n, char f, char a, char t) {
    if (n == 0)
        return;

    hanoi_std(n - 1, f, t, a);
    printf("%c -> %c\n", f, t);
    steps++;
    hanoi_std(n - 1, a, f, t);
}

// 奇偶分散：奇數到 o，偶數到 e
void distribute(int n, char f, char o, char e) {
    if (n == 0) 
        return;

    // 目的
    char t = (n % 2 ? o : e);

    // 這層正確 則處理上一層 這層結束
    if (f == t) {
        distribute(n - 1, f, o, e);
        return;
    }

    // 找出 暫存（ 非位置和目的 ）
    char a = 'A' + 'B' + 'C' - f - t;

    // 先把上層移到 暫存
    hanoi_std(n - 1, f, t, a);

    // 移動 n 到目的
    printf("%c -> %c\n", f, t);
    steps++;

    // 將在 暫存 的 n-1 層繼續分散
    distribute(n - 1, a, o, e);
}

int main() {
    int n;
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    // 起始 A，奇數 B，偶數 C
    distribute(n, 'A', 'B', 'C');
    printf("Total steps = %lld\n", steps);
    return 0;
}