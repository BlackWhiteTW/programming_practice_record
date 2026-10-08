
import java.util.Scanner;

public class C3_2 {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (; n > 0; n--) {
            int a = sc.nextInt(), b = sc.nextInt();
            long sum = 1;

            if (a > b) {
                int temp = a;
                a = b;
                b = temp;
            }

            for (int i = 1; i < a; i++) {
                sum = sum * (b - 1 + i) / i;
            }

            System.out.println(sum);
        }

        sc.close();
    }
}
