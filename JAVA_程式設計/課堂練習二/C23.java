
import java.util.Scanner;

public class C23 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        sc.nextLine(); // 換行符號

        while (t-- > 0) {

            String input = sc.nextLine();
            int count = 0;

            if (input.length() != 11) {
                System.out.println("-1");
                sc.close();
                return;
            }

            for (int i = 0; i < input.length(); i++) {
                if (i % 2 == 0) {
                    count += (input.charAt(i) - '0') * 3;
                } else {
                    count += (input.charAt(i) - '0');
                }
                count %= 10;
            }

            System.out.println(10 - count);
        }

        sc.close();
    }
}
