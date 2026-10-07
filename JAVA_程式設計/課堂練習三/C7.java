
import java.util.Scanner;
import java.util.ArrayList;

public class C7 {

    public static boolean is_palindrome(String str) {
        for (int i = 0; i < str.length() / 2 + 1; i++) {
            if (str.charAt(i) != str.charAt(str.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<String> list = new ArrayList< String>();
        String str = sc.nextLine();
        int max_length = 0;

        for (int i = 0; i < str.length(); i++) {
            for (int j = i + 1; j <= str.length(); j++) {
                String substr = str.substring(i, j);
                if ( substr.length() > max_length) {
                    if (is_palindrome(substr)) {
                        list.clear();
                        list.add(substr);
                        max_length = substr.length();
                    }
                } else if (substr.length() == max_length) {
                    if (is_palindrome(substr)) {
                        list.add(substr);
                    }
                }
            }
        }

        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + " ");
        }

        sc.close();
    }
}
