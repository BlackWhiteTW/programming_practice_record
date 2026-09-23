
import java.text.DecimalFormat;
import java.util.Scanner;

public class C11 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat f1 = new DecimalFormat("0.00");
        float x1, x2, y1, y2, d;

        x1 = scanner.nextFloat();
        y1 = scanner.nextFloat();
        x2 = scanner.nextFloat();
        y2 = scanner.nextFloat();

        d = (float) Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2));

        System.out.println(f1.format(d));

        scanner.close();
    }
}
