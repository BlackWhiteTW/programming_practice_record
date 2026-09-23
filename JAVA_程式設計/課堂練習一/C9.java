
import java.text.DecimalFormat;
import java.util.Scanner;

public class C9 {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        DecimalFormat f1 = new DecimalFormat("0.0");
        float arr[] = new float[5], sum = 0, avg = 0;
        for (int i = 0; i < arr.length; i++) {
            arr[i] = scanner.nextFloat();
            sum += arr[i];
        }
        avg = sum / 5;
        System.out.println(f1.format(sum));
        System.out.println(f1.format(avg));
    }
}
