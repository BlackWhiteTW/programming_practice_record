
import java.util.Scanner;

public class C5 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int c2 = 0, c4 = 0, c6 = 0, c8 = 0;

        String input = sc.nextLine();

        for (char ch : input.toCharArray()) {
            switch (ch) {
                case '2' ->
                    c2++;
                case '4' ->
                    c4++;
                case '6' ->
                    c6++;
                case '8' ->
                    c8++;
                default -> {
                }
            }
        }

        System.out.printf("2 %d\n4 %d\n6 %d\n8 %d", c2, c4, c6, c8);

        sc.close();
    }
}
