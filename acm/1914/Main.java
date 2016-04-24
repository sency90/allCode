import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());

        BigInteger y = new BigInteger("2");
        y = y.pow(n).subtract(new BigInteger("1"));
        bw.write(y.toString()+"\n");
        if(n<=20) f(n,1,3);
        bw.close();
    }

    static void f(int n, int x, int y) throws Exception{
        if(n==0) return;
        f(n-1,x,6-x-y);
        bw.write(x+" "+y+"\n");
        f(n-1,6-x-y,y);
    }
}
