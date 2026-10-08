
import java.text.DecimalFormat;
import java.util.Scanner;

public class C16 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("0");
        int x, y, z, n;

        while (true) {
            x = sc.nextInt();
            y = sc.nextInt();
            z = sc.nextInt();

            if (x <= 0 || y <= 1 || z <= 0) {
                break;
            }
            n = z / x;

            System.out.print(df.format(n + (n - 1) / (y - 1)) + " ");
            System.out.print(df.format(z % x) + " ");
            System.out.println(df.format((n - 1) % (y - 1) + 1));
        }

        sc.close();
    }
}
