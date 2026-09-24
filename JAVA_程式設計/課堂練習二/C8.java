
import java.util.Scanner;

public class C8 {

    public static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m;

        n = sc.nextInt();
        m = sc.nextInt();

        int g = gcd(n, m), lcm = n * m / g, sum = m * n / g / g;

        System.out.println(sum + " " + lcm);

        sc.close();
    }
}

/*
sum = lcm / n * lcm / m
(lcm = n * m / gcd(n, m))
= ( n * m / gcd(n, m) ) / n * ( n * m / gcd(n, m) ) / m
= ( m / gcd(n, m) ) * ( n / gcd(n, m) )
= ( n * m ) / ( gcd(n, m) * gcd(n, m) )
 */
