import java.util.Scanner;
import java.math.BigDecimal;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String a;
        int b;
        a = in.next();
        BigDecimal x = new BigDecimal(a);

        b = in.nextInt();
        x = x.pow(b);

        System.out.print(x.toPlainString());
        in.close();
    }
}
