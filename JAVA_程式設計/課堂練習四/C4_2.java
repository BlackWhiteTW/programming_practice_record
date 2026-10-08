
import java.util.Arrays;
import java.util.Scanner;

public class C4_2 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] work = new int[n][2];

        for (int i = 0; i < n; i++) {
            work[i][0] = sc.nextInt();
            work[i][1] = sc.nextInt();
        }

        Arrays.sort(work, (a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            } else {
                return a[1] - b[1];
            }
        });

        int count = 0;
        int lastEndTime = -1;

        for (int i = 0; i < n; i++) {
            if (work[i][0] >= lastEndTime) {
                count++;
                lastEndTime = work[i][1];
            }
        }

        System.out.println(count);

        sc.close();
    }
}
