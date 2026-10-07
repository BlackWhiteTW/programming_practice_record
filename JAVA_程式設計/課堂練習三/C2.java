
import java.util.Arrays;
import java.util.Scanner;

public class C2 {

    public static boolean is_prime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            int input = sc.nextInt();
            if (is_prime(input)) {
                arr[i] = input;
            }
        }

        Arrays.sort(arr);

        for (int i = 0; i < n; i++) {
            if (arr[i] != 0) {
                System.out.print(arr[i] + " ");
            }
        }

        sc.close();
    }
}
