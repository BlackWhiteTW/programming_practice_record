
import java.util.Arrays;
import java.util.Scanner;

public class C4 {

    public static int DFS(int[][] array, int len, int work_end, int now, int w) {
        int max_current = w;
        for (int i = now; i < len; i++) {
            if (work_end <= array[i][0]) {
                int res = DFS(array, len, array[i][1], i + 1, w + 1);
                max_current = Math.max(max_current, res);
            }
        }
        return max_current;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int len = sc.nextInt();
        int work[][] = new int[len][2];
        int max_w = 0;

        for (int i = 0; i < len; i++) {
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

        for (int i = 0; i < len; i++) {
            max_w = Math.max(max_w, DFS(work, len, work[i][1], i + 1, 1));
        }

        System.out.println(max_w);
        sc.close();
    }
}
