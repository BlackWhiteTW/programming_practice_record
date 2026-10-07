
import java.util.Scanner;

public class C18 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b, ans = 0;

        a = sc.nextInt();
        b = sc.nextInt();

        if (a > b) {
            a = a + b;
            b = a - b;
            a = a - b;
        }

        for (; a <= b; a++) {
            if (a % 3 == 0 || a % 5 == 0) {
                ans += a;
            }
        }

        System.out.println(ans);

        sc.close();
    }
}
