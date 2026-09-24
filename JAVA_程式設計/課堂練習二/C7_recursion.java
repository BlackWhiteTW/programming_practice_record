
import java.util.Scanner;

public class C7_recursion {

    public static long f(int n) {
        if (n == 0) {
            return 1;
        } else {
            return f(n - 1) * 2 + n;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long ans = 0;

        for (int i = 0; i <= n; i++) {
            ans += f(i);
        }

        System.out.println(ans);

        sc.close();
    }

}
