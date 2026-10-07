
import java.util.ArrayList;
import java.util.Scanner;

public class C21 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list_int = new ArrayList<Integer>();
        ArrayList<Character> list_char = new ArrayList<Character>();
        String input = sc.nextLine();

        for (int i = 0; i < input.length(); i++) {
            list_char.add(input.charAt(i));
            int count = 1;
            while (i < input.length() - 1 && input.charAt(i) == input.charAt(i + 1)) {
                i++;
                count++;
            }
            list_int.add(count);
        }

        for (int i = 0; i < list_int.size(); i++) {
            if (list_int.get(i) == 1) {
                System.out.print(list_char.get(i));

            } else if (list_int.get(i) == 2) {
                System.out.print(list_char.get(i));
                System.out.print(list_char.get(i));
            } else {
                System.out.print(list_int.get(i));
                System.out.print(list_char.get(i));
            }
        }

        sc.close();
    }
}
