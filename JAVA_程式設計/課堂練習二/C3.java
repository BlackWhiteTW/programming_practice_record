
import java.util.Scanner;

public class C3 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;

        n = sc.nextInt();

        for (int i = 1; i * 63 <= n; i++) {
            System.out.print(i * 63 + " ");
        }

        sc.close();
    }
}
