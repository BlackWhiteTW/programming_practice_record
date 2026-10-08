
import java.util.Scanner;

public class C3 {

    public static long C(int n, int r) {
        long result = 1;
        for (int i = 0; i < r; i++) {
            result *= (n - i);
            result /= (i + 1);
        }
        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (; n > 0; n--) {
            int a = sc.nextInt(), b = sc.nextInt();

            System.out.println(C(a + b - 2, a - 1));
        }

        sc.close();
    }
}
