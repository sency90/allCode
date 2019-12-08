import java.util.Scanner;

public class Main{
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for (int i = 1; i <= 2 * n - 1; i++) {
            for (int j = 1; j <= 2 * n - 1; j++) {
                if (i <= n && i > j) {
                    System.out.print("_");
                }
                else if (i <= n && 2 * n - i < j) {
                    System.out.print("_");
                }
                else if (i > n && i < j) {
                    System.out.print("_");
                }
                else if (i > n && 2 * n - i > j) {
                    System.out.print("_");
                }
                else {
                    System.out.print('*');
                }
            }
            System.out.println();

        }
    }
}
