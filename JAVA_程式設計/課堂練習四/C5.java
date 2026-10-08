
import java.util.Arrays;
import java.util.Scanner;

public class C5 {

    public static int DFS(int[][] arr, int len, int now, int cost, int k, int ks) {
        int max_current = cost;
        for (int i = now; i < len; i++) {
            if (arr[i][0] + k <= ks) {
                int res = DFS(arr, len, i + 1, arr[i][1] + cost, arr[i][0] + k, ks);
                max_current = Math.max(max_current, res);
            }
        }
        return max_current;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] arr = new int[n][2];

        for (int i = 0; i < n; i++) {
            arr[i][0] = sc.nextInt();
            arr[i][1] = sc.nextInt();
        }

        int ks = sc.nextInt();

        Arrays.sort(arr, (a, b) -> {
            if (a[0] != b[0]) {
                return a[0] - b[0];
            } else {
                return b[1] - a[1];
            }
        });

        System.out.println(DFS(arr, n, 0, 0, 0, ks));

        sc.close();
    }
}
