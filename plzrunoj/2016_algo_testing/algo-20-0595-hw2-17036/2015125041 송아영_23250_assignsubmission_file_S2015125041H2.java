import java.util.Scanner;

public class S2015125041H2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int x[] = new int[n];
		int result=-1, bigger;
		
		sc.nextLine();
		String tmp = sc.nextLine();
		
		for(int i=0; i<n; i++){
			x[i] = Integer.parseInt(tmp.split(" ")[i]);
		}
		
		for(int i=0; i<n; i++){
			bigger = 0;
			for(int j=0; j<n; j++){
				if(x[i]<=x[j]){
					bigger++;
				}
			}
			if(x[i] <= bigger){
				if(result<x[i])
					result=x[i];
			}
		}
		if(result!=-1)
			System.out.println(result);
	}
}