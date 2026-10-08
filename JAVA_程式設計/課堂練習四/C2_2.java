
import java.util.Scanner;

public class C2_2 {

    /*
    public static long f(long a, long b, int n, int index) {

        if (index == n) {
            return b;
        } else {
            return f(b, a + b, n, index + 1);
        }
    }
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long a = 1, b = 1;

        for (int i = 1; i < n; i++) {
            long temp = a;
            a = b;
            b = temp + b;
        }

        System.out.println(b);

        sc.close();
    }
}
