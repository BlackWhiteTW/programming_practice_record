
import java.text.DecimalFormat;
import java.util.Scanner;

public class C5 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat f1 = new DecimalFormat("0.00");
        float a, b, c, ans;

        a = scanner.nextFloat();
        b = scanner.nextFloat();
        c = scanner.nextFloat();

        ans = (a + b) * c * 0.5f;

        System.out.println(f1.format(ans));

        scanner.close();
    }
}
