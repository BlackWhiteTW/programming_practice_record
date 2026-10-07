
import java.util.Scanner;

public class C4 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String list = "0123456789ABCDEF";
        int dec = 0;

        String input = sc.nextLine();

        for (int i = 0; i < input.length(); i++) {
            dec += (int) Math.pow(16, input.length() - 1 - i) * list.indexOf(input.charAt(i));
        }
        System.out.println(dec);

        sc.close();
    }
}
