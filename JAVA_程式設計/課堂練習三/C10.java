
import java.util.Arrays;
import java.util.Scanner;

public class C10 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int list[] = new int[3];
            for (int i = 0; i < 3; i++) {
                list[i] = sc.nextInt();
            }

            Arrays.sort(list);

            if (list[0] + list[1] > list[2]) {
                System.out.print("1 ");
                if (list[0] == list[1] || list[1] == list[2] || list[0] == list[2]) {
                    System.out.println("1");
                } else {
                    System.out.println("0");
                }
            } else {
                System.out.println("0");
            }

        }

        sc.close();
    }
}
