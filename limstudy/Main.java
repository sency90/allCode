//package main;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int[] cnt = new int[42];
        int ans=0;

        int x;
        for (int i=0; i<10; i++) {
            x = scan.nextInt();
            x %= 42;
            if(cnt[x]++ == 0) ans++;
        }

        System.out.println(ans);
    }
}
