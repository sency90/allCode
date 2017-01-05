package S2015125018H3;

import java.util.Scanner;

public class S2015125018H3 {
	
	long D[][][] = new long[101][101][101];
	long rest = 1000000007;
	
	public static void main(String[] args) {
		S2015125018H3 aa = new S2015125018H3();
		
		Scanner s = new Scanner(System.in);
		int n = s.nextInt();
		int l = s.nextInt();
		int r = s.nextInt();
		
		long tmp = aa.building(n, l, r);		
		System.out.println(tmp);
	}
	
	public long building(int n,int l,int r){
		if(D[n][l][r] != 0){
			return D[n][l][r];
		}
		if(l==1 && r==1){
			if (n ==1){
				return (long)1;
			}else{
				return (long)0;
			}
		}else if( l<1 || r<1 || l+r > n+1){
			return 0;
		}
		return D[n][l][r] = ((n-2)*building(n-1,l,r)+building(n-1,l-1,r)+building(n-1,l,r-1))%rest;
	}
	
	
}
