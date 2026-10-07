
import java.util.Scanner;

public class C22 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] str = sc.nextLine().split(" ");
        String str_A = str[0], str_B = str[1];
        int A = 0, B = 0;

        for (int i = 0; i < str_A.length(); i++) {
            if (str_A.charAt(i) == str_B.charAt(i)) {
                A++;
            } else if (str_B.indexOf(str_A.charAt(i)) != -1) {
                B++;
            }
        }

        System.out.println(A + " " + B);

        sc.close();
    }
}
