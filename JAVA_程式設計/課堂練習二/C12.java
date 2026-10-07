
import java.util.ArrayList;
import java.util.Scanner;

public class C12 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        ArrayList<Integer> list_int = new ArrayList<Integer>();
        ArrayList<Character> list_char = new ArrayList<Character>();
        int input = sc.nextInt(), i = 2;

        while (input != 0) {
            if (input == i) {
                list_int.add(i);
                break;
            } else if (input % i == 0) {
                list_int.add(i);
                int t = 0;
                while (input % i == 0) {
                    t++;
                    input /= i;
                }
                if (t > 1) {
                    list_char.add('^');
                    list_int.add(t);
                }
                list_char.add('*');
            } else {
                i++;
            }
        }

        for (int j = 0; j < list_int.size(); j++) {
            System.out.print(list_int.get(j));
            if (j < list_char.size()) {
                if (list_char.get(j) == '*') {
                    System.out.print(" " + list_char.get(j) + " ");
                } else {
                    System.out.print(list_char.get(j));
                }
            }
        }

        sc.close();
    }
}
