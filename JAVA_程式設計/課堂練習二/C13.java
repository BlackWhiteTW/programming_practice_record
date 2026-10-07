
import java.util.ArrayList;
import java.util.Scanner;

public class C13 {

    private static boolean isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long input = sc.nextLong();
        ArrayList<Long> list_int = new ArrayList<Long>();
        int i = 2;
        long temp = 0;
        while (true) {
            if (isPrime(i) && isPrime((int) (Math.pow(2, i) - 1))) {
                temp = (long) Math.pow(2, i - 1) * ((long) Math.pow(2, i) - 1);
                if (temp > input) {
                    break;
                } else {
                    list_int.add(temp);
                }
            }
            i++;
        }
        for (int j = 0; j < list_int.size(); j++) {
            System.out.print(list_int.get(j));
            if (j < list_int.size() - 1) {
                System.out.print(" ");
            }
        }

        sc.close();
    }
}

/*
完美數公式
2^(p-1) * (2^p - 1)
 */
