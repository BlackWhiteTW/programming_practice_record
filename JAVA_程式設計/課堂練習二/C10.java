
import java.util.Scanner;

public class C10 {

    public static int recursion(int n, int index) {
        if (n <= 1) {
            return index;
        } else if (n % 2 == 1) {
            return recursion(n * 3 + 1, index + 1);
        } else {
            return recursion(n / 2, index + 1);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int index, n = sc.nextInt();

        index = recursion(n, 0);

        System.out.println(index);

        sc.close();
    }
}
