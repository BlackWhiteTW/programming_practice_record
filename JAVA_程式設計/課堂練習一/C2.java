
import java.util.Scanner;

public class C2 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str;
        int c, e, m;

        str = scanner.nextLine();
        c = scanner.nextInt();
        e = scanner.nextInt();
        m = scanner.nextInt();

        System.out.println(str + " " + c + "," + e + "," + m);
        scanner.close();
    }
}
