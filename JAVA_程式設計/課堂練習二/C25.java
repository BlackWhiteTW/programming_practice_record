
import java.util.Scanner;

public class C25 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), index = 1;
        long num = 1, ans = 1;

        while (index < n) {

            if (num % 2 == 0) {
                num /= 2;
            } else if (num % 3 == 0) {
                num /= 3;
            } else if (num % 5 == 0) {
                num /= 5;
            } else {
                ans++;
                num = ans;
            }

            if (num == 1) {
                index++;
            }
        }

        System.out.println(ans);

        sc.close();
    }
}
