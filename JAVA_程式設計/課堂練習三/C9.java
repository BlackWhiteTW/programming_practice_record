
import java.util.Scanner;

public class C9 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String[] list = sc.nextLine().split(" ");

        for (String str : list) {
            int n = 1, i = Integer.parseInt(str);
            for (int j = 2; j * j <= i; j++) {
                if (i % j == 0 && j * j != i) {
                    n += j + i / j;
                } else if (i % j == 0) {
                    n += j;
                }
            }
            if (n > i) {
                System.out.println("1");
            } else if (n < i) {
                System.out.println("2");
            } else {
                System.out.println("3");
            }
        }

        sc.close();
    }
}


/*
    1 + 2 +3 +5 +6 10 +15 = 42
    1 + 2 +13 = 16
    1 + 2 + 4 + 7 + 14 = 28
 */
