
import java.text.DecimalFormat;
import java.util.Scanner;

public class C7 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat f1 = new DecimalFormat("0.00");
        float in_put, out_put;

        in_put = scanner.nextFloat();

        out_put = (in_put - 32) * 5 / 9;

        System.out.println(f1.format(out_put));
    }
}
