
import java.util.Scanner;

public class C17 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int input = sc.nextInt(), ans = 0;
        while (input > 0) {
            if (input >= 10) {
                ans += input / 10 * 800;
                input = input % 10;
            } else if (input >= 5) {
                ans += input / 5 * 440;
                input = input % 5;
            } else if (input >= 2) {
                ans += input / 2 * 180;
                input = input % 2;
            } else {
                ans += 100;
                input = 0;
            }
        }

        System.out.println(ans);

        sc.close();
    }
}
