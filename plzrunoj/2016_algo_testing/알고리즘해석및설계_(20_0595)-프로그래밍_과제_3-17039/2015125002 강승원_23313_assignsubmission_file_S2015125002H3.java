import java.util.*;

public class S2015125002H3 {
	static long[][][] a = new long[101][101][101];
	public static long func(int n,int l, int r){
		if(a[n][l][r]>0) return a[n][l][r];
		if(l>n||r>n||r==0||l==0||n==0) return 0;
		if(n==1&&r==1&&l==1) return 1;
		
		a[n][l][r] = func(n-1,l-1,r)+func(n-1,l,r-1)+(n-2)*func(n-1,l,r);
		return a[n][l][r];
	}
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		
		int n = s.nextInt();
		int l = s.nextInt();
		int r = s.nextInt();
		long answer = func(n,l,r);
		answer = answer%1000000007;
		System.out.printf("%d",answer);
	}
}