
import java.util.ArrayList;
import java.util.Scanner;

public class C19 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        char ch = Character.toLowerCase(input.charAt(input.length() - 1));
        ArrayList<Integer> list_int = new ArrayList<Integer>();

        for (int i = 0; i < input.length() - 1; i++) {
            if (Character.toLowerCase(input.charAt(i)) == ch) {
                list_int.add(i);
            }
        }

        for (int i = 1; i < list_int.size(); i++) {
            System.out.print(list_int.get(i) - list_int.get(i - 1));
            if (i < list_int.size() - 1) {
                System.out.print(" ");
            }
        }

        sc.close();
    }
}
