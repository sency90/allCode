//package main;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int[] su = new int[10];
        int[] cnt = new int[42];
        int ans=0;

        for (int i=0; i<10; i++) {
            su[i] = scan.nextInt();
            su[i] = su[i] % 42;
        }
        for (int i : su) cnt[i]++;
        for (int i=0; i<42; i++) {
            if(cnt[i]>0) ans++;
        }

        System.out.println(ans);
    }
}
