
import java.util.Scanner;

public class C9 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m;

        n = sc.nextInt();
        m = sc.nextInt();

        long ans = 0, index = 1;
        for (int i = 1; i <= n; i++) {
            index *= 2;
        }

        for (int i = n; i <= m; i++) {
            ans += index;
            index *= 2;
        }

        System.out.println(ans);

        sc.close();
    }
}
