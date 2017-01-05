package h3;

import java.util.*;


//순열을 구해 각 경우의 L, R을 구해서 맞다면 totalcnt++함
public class S2012122374H3 {

	
	static int[] input = new int[3];
	static int totalcnt = 0;
	
	
	public static void main(String[] args) {
		
		Scanner scan = new Scanner(System.in);
		
		
		for(int i=0; i<3; i++)
			input[i] = scan.nextInt();
		
		if(!(0 < input[0] && input[0] <= 100))
			System.exit(0);

		
		perm(input[0]);
		System.out.println(totalcnt%1000000007);		
	}
	
	public static void perm(int n){
		
		int[] arr = new int[n];
		
		for(int i=0; i<n; i++)
			arr[i] = i+1;
		
		perm(arr, 0, n, n);
		
		
	}

	public static void perm(int[] arr, int depth, int n, int k) {

		if (depth == k) {
			func(arr,k);
			return;
		}

		for (int i = depth; i < n; i++) {
			swap(arr, i, depth);
			perm(arr, depth + 1, n, k);
			swap(arr, i, depth);
		}

	}

	public static void swap(int[] arr, int i, int j) {
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	public static void func(int[] arr, int k) {

		
		int index = 0;
		int leftcnt = 0;
		int rightcnt = 0;
		
		
		for(int i=0; i<k; i++)
			if(arr[i] == input[0])
				index = i;
		
		for(int i=0; i<=index; i++){
			if(arr[0] <= arr[i] && arr[i] <= arr[index])
				leftcnt++;
		}
		
		
		for(int i=index; i<k; i++){
			if(arr[k-1] <= arr[i] && arr[i] <= arr[index])
				rightcnt++;
		}
		
		
		if(leftcnt == input[1] && rightcnt == input[2])
			totalcnt++;
		
		
	}

}
