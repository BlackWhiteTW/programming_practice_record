
import java.util.Scanner;

public class C3 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int l, h;
        float a;

        l = scanner.nextInt();
        h = scanner.nextInt();
        a = (float) l * h;

        System.out.println(String.format("%.2f", a));

        scanner.close();
    }
}
