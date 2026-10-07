
import java.util.ArrayList;
import java.util.Comparator;
import java.util.Scanner;

public class C15 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<Integer>();

        for (int i = 0; i < 3; i++) {
            list.add(sc.nextInt());
        }

        list.sort(Comparator.naturalOrder());

        list.add(list.get(0) * list.get(0) + list.get(1) * list.get(1) - list.get(2) * list.get(2));

        if (list.get(3) == 0) {
            System.out.println("right triangle");
        } else {
            if (list.get(0) + list.get(1) > list.get(2)) {
                if (list.get(3) > 0) {
                    System.out.println("acute triangle");
                } else {
                    System.out.println("obtuse triangle");
                }
            } else {
                System.out.println("x");
            }
        }

        sc.close();
    }
}
