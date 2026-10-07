
import java.text.DecimalFormat;
import java.util.Scanner;

public class C13 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("0.0000");
        int n, s;
        double area = 0;

        n = sc.nextInt();
        s = sc.nextInt();

        area = (double) (n * s * s) / (4 * Math.tan(Math.PI / n));

        System.out.println("Area: " + df.format(area));

        sc.close();
    }
}
