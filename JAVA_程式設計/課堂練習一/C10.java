
import java.text.*;
import java.util.Scanner;

public class C10 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat f1 = new DecimalFormat("0.0");
        int min, sec, km;
        float mile;

        min = scanner.nextInt();
        sec = scanner.nextInt();
        km = scanner.nextInt();

        mile = (float) km / 1.6f / ((float) min / 60f + (float) sec / 3600f);
        System.out.println(f1.format(mile));
    }
}
