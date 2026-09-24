
import java.util.ArrayList;
import java.util.Scanner;

public class C1 {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<Integer>();
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        for (int i = 1; i <= (int) Math.sqrt(n); i++) {
            if (n % i == 0) {
                list.add(i);
                if (i != n / i) {
                    list.add(n / i);
                }
            }
        }

        list.sort(null);

        for (int num : list) {
            System.out.print(num + " ");
        }

        sc.close();
    }
}
