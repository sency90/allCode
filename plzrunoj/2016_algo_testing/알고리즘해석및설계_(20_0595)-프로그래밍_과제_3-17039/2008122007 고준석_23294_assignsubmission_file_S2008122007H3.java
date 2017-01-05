import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class S2008122007H3{

	public static void main(String[] args) throws IOException{
		
		int a[] = new int[3];
		int arr[] = new int[100];
		
		
		System.out.print("N L R 입력 : ");
        InputStreamReader r1 = new InputStreamReader(System.in);
        BufferedReader b1 = new BufferedReader(r1);
        String num = b1.readLine();
        
        String[] slice1 = num.split(" ");
        
        for(int i = 0; i <= 2; i++){
             a[i] = Integer.parseInt(slice1[i]);
            }
        
        for(int j = 0; j <= a[0]; j++){
        	arr[j] = j+1;
        }
        
//		perm(arr, 0, a[0], a[0]); // 출력 테스트용
		caculate(a[0], a[1], a[2]);
	}
/*
	public static void perm(int[] arr, int depth, int n, int k){

		if(depth == k){ 
			print(arr,k);
			return;
		}

		for(int i = depth; i < n; i++){
			swap(arr, i, depth);
			perm(arr, depth + 1, n, k);
			swap(arr, i, depth);
		}

	}

	public static void swap(int[] arr, int i, int j){
		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	public static void print(int[] arr, int k){

		for(int i = 0; i < k; i++) {
			if(i == k - 1)
				System.out.println(arr[i]);
			else
				System.out.print(arr[i] + " ");
		}
	}
	*/
	// 출력 테스트용
	public static void caculate(int a, int b, int c){
		int brr[][][] = new int[101][101][101];
		
		brr[1][1][1] = 1;
	    brr[2][2][1] = brr[2][1][2] = 1;
	    
		for (int i = 3; i <= a; i++) {
	        brr[i][i][1] = brr[i][1][i] = 1;
	        for (int j = 1; j <= a; j++) {
	            for (int k = 1; k <= a; k++) {
	            	int temp;
	                temp = brr[i - 1][j][k];
	                temp = (temp * (i - 2)) % 1000000007;
	                temp = (temp + brr[i - 1][j - 1][k]) % 1000000007;
	                temp = (temp + brr[i - 1][j][k - 1]) % 1000000007;
	 
	                brr[i][j][k] = temp;
	            }
	        }
	    }
		
		System.out.print("경우 수 : "+ brr[a][b][c]);
	}
}

