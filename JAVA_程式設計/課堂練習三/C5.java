
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class C5 {

    private static boolean is_p(int n) {
        if (n <= 1) {
            return false;
        } else {
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    return false;
                }
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> list = new ArrayList< Integer>();
        while (n-- > 0) {
            int num = sc.nextInt();
            if (is_p(num)) {
                String str = Integer.toString(num);
                boolean is_palindrome = true;
                for (int i = 0; i < str.length() / 2 + 1; i++) {
                    if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
                        is_palindrome = false;
                        break;
                    }
                }
                if (is_palindrome) {
                    list.add(num);
                }
            }
        }

        list.sort(Comparator.naturalOrder());

        for (int i : list) {
            System.out.print(i + " ");
        }

        sc.close();
    }
}
