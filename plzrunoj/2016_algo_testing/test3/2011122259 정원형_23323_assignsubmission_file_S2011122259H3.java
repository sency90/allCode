import java.util.Scanner;

public class S2011122259H3 {
	public static void main(String args[]){
		long n,l,r,result ;
		Scanner in = new Scanner(System.in);
		n= in.nextLong();
		l = in.nextLong();
		r = in.nextLong();
		result = method(n,l,r)%1000000007;
		System.out.println(result);
	}
	
	public static long method(long n, long l, long r){
		if( n <2){
			if(n ==1 && l == 1 && r ==1)
				return 1;
			else return 0;
		}
		
		return (n-2)*method(n-1,l,r)+ method(n-1, l-1, r) + method(n-1, l, r-1);
	}
}