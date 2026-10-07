
import java.util.ArrayList;
import java.util.Scanner;

public class C20 {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine(); // 读取换行符
        String input = sc.nextLine();
        for (int t = 0; t < n; t++) {
            ArrayList<Integer> list_int = new ArrayList<Integer>();
            input = sc.nextLine();

            for (int i = 0; i < input.length() - 1; i++) {
                list_int.add(Math.abs((int) input.charAt(i) - (int) input.charAt(i + 1)));
            }

            for (int i = 0; i < list_int.size(); i++) {
                System.out.print(list_int.get(i));
            }

            System.out.println();

        }
        sc.close();
    }
}
