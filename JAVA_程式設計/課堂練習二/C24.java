
import java.util.Scanner;

public class C24 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        long max = 0;

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            long currentProduct = 1;
            for (int j = i; j < n; j++) {
                currentProduct *= arr[j];
                if (currentProduct > max) {
                    max = currentProduct;
                }
            }
        }

        System.out.println(max);

        sc.close();
    }
}
