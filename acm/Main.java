import java.util.Scanner;
import java.math.BigInteger;
public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);int n = in.nextInt();
        BigInteger y = new BigInteger("2");
        y = y.pow(n).subtract(new BigInteger("1"));
        System.out.println(y.toString());
        if(n<=20) f(n,1,3);
        in.close();
    }

    public static void f(int n, int x, int y) {
        if(n==0) return;
        f(n-1,x,6-x-y);
        System.out.println(x + " " + y);
        f(n-1,6-x-y,y);
    }
}

