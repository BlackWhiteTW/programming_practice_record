
import java.text.*;
import java.util.Scanner;

public class C16 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b;
        char op;
        DecimalFormat df = new DecimalFormat("0.00");

        a = sc.nextInt();
        b = sc.nextInt();
        op = sc.next().charAt(0);

        float ans = 0;
        switch (op) {
            case '+':
                ans = a + b;
                break;
            case '-':
                ans = a - b;
                break;
            case '*':
                ans = a * b;
                break;
            case '/':
                ans = (float) a / b;
                break;
            case '%':
                ans = a % b;
                break;
        }

        System.out.println(df.format(ans));

        sc.close();
    }
}
