
import java.util.Scanner;

public class C7 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long ans = 1, f = 1;

        for (int i = 1; i <= n; i++) {
            f = f * 2 + i;
            ans += f;
        }

        System.out.println(ans);

        sc.close();
    }

}
