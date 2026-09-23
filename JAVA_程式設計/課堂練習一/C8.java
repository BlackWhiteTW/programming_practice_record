
import java.text.DecimalFormat;
import java.util.Scanner;

public class C8 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat f1 = new DecimalFormat("0.00");
        double r, R, area, pi = Math.PI;

        r = scanner.nextDouble();

        R = r * 2 * pi;
        area = pi * r * r;

        System.out.println(f1.format(r));
        System.out.println(f1.format(R));
        System.out.println(f1.format(area));

        scanner.close();
    }
}
