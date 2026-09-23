
import java.text.DecimalFormat;
import java.util.Scanner;

public class C4 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat f1 = new DecimalFormat("0.00");
        float w, h, p, a;

        h = scanner.nextFloat();
        w = scanner.nextFloat();

        p = (w + h) * 2;
        a = w * h;

        System.out.println("Height = " + f1.format(h));
        System.out.println("Width = " + f1.format(w));
        System.out.println("Perimeter = " + f1.format(p));
        System.out.println("Area = " + f1.format(a));

        scanner.close();
    }
}
