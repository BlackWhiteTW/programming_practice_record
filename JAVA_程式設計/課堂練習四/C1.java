
import java.util.Scanner;

public class C1 {

    public static long f(long a, long b, int n, int index) {
        if (index == n) {
            return a;
        } else {
            return f(b, a + b, n, index + 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        System.out.println(f(0, 1, n, 0));

        sc.close();
    }
}
