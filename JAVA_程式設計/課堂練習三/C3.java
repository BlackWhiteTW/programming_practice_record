
import java.util.Scanner;

public class C3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), k = sc.nextInt();
        boolean[] arr = new boolean[n + 1];

        for (int i = 1; i <= k; i++) {
            for (int j = i; j <= n; j += i) {
                arr[j] = !arr[j];
            }
        }

        for (int i = 1; i <= n; i++) {
            if (arr[i]) {
                System.out.print(i + " ");
            }
        }

    }
}
