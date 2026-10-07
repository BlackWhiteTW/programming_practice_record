
import java.util.ArrayList;
import java.util.Scanner;

public class C14 {

    private static boolean isArmstrong(int n) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        int sum = 0;
        for (int i = n; i > 0; i /= 10) {
            list.add(i % 10);
        }
        for (int i = 0; i < list.size(); i++) {
            sum += Math.pow(list.get(i), list.size());
        }
        if (sum == n) {
            return true;
        } else {
            return false;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        ArrayList<Integer> list = new ArrayList<Integer>();
        int n, m;

        n = sc.nextInt();
        m = sc.nextInt();

        for (; n <= m; n++) {
            if (isArmstrong(n)) {
                list.add(n);
            }
        }

        if (list.size() == 0) {
            System.out.println("none");
        } else {
            for (int i = 0; i < list.size(); i++) {
                System.out.print(list.get(i));
                if (i < list.size() - 1) {
                    System.out.print(" ");
                }
            }
        }

        sc.close();
    }
}
