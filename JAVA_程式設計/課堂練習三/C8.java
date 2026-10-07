
import java.util.Scanner;

public class C8 {

    public static int sum(int list[]) {
        int sum = 0;
        for (int i : list) {
            if (i % 3 == 0 && i % 2 != 0) {
                sum += i;
            }
        }
        return sum;
    }

    public static void main(String[] args) {
        {
            Scanner sc = new Scanner(System.in);
            String[] list = sc.nextLine().split(" ");
            int list_i[] = new int[list.length];

            for (int i = 0; i < list.length; i++) {
                list_i[i] = Integer.parseInt(list[i]);
            }

            System.out.println(sum(list_i));

            sc.close();
        }
    }
}
