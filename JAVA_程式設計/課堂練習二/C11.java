
import java.util.Scanner;

public class C11 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        float m, kg, BMI, i;
        char ch;

        m = ((float) sc.nextInt()) / 100;
        kg = sc.nextFloat();
        BMI = kg / (m * m);
        i = m * m * 22;
        if (BMI < 18.5) {
            ch = 'A';
        } else if (BMI < 24) {
            ch = 'B';
        } else if (BMI < 27) {
            ch = 'C';
        } else if (BMI < 30) {
            ch = 'D';
        } else if (BMI < 35) {
            ch = 'E';
        } else {
            ch = 'F';
        }

        System.out.println(BMI);
        System.out.println(i);
        System.out.println(ch);

        sc.close();
    }
}
