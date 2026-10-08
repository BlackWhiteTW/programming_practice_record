
import java.text.DecimalFormat;
import java.util.Scanner;

public class C14 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DecimalFormat df = new DecimalFormat("0.00");
        int m = sc.nextInt();
        double rate = sc.nextDouble();
        int n = sc.nextInt();

        System.out.println(df.format(m * Math.pow(1 + rate / 100, n)));

        sc.close();
    }
}
