
import java.util.Scanner;

public class C2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, m;
        long N, M, ans;

        n = sc.nextInt();
        m = sc.nextInt();

        N = (long) n * (n - 1) * (2 * n - 1) / 6;
        M = (long) m * (m + 1) * (2 * m + 1) / 6;
        ans = M - N;

        System.out.println(ans);

        sc.close();
    }
}

/*
    1^2 ~ (N-1)^2 
    = (N-1)((N-1)+1)((N-1)*2+1)/6
    = (N-1)(N)(2N-1)/6

    1^2 ~ M^2
    = M(M+1)(2M+1)/6
 */
