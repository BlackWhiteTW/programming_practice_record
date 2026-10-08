
import java.util.Scanner;

public class C2 {

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
        long sum = 1;

        for (int i = n / 2; i > 0; i--) {
            sum += C(n - i, i);
        }

        System.out.println(sum);

        sc.close();
    }
}
