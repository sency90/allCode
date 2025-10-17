package algho;
import java.util.Arrays;
import java.util.Scanner;

public class S2015125068H2 {
	public static void main(String[] args) {
		
		Scanner s =new Scanner(System.in);
		int size=s.nextInt();
		int[] num= new int[size];
		int ans=0;
		for(int i=0; i<size; i++){
			num[i]=s.nextInt();
		}
		
		Arrays.sort(num);
		for(int i=0; i<size; i++){
			if(num[i]<=size-i){
				ans=num[i];
			}
		}
		
		System.out.print(ans);	
	}

}
