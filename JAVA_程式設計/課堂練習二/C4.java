
import java.util.Scanner;

public class C4 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        long ans;

        n = sc.nextInt();

        ans = 15 * (long) Math.pow(n * (n + 1) / 2, 2);

        System.out.println(ans);

        sc.close();
    }
}

/* 
    F=(1×3×5)＋(2×6×10)＋(3×9×15)＋．．．＋(N×M×L)
    = 15*1^3 + 15*2^3 + 15*3^3 + ... + 15*N^3
    = 15(1^3 + 2^3 + 3^3 + ... + N^3)
    = 15(1 + 2 + 3 + ... + N)^2
    = 15(N(N+1)/2)^2
 */
