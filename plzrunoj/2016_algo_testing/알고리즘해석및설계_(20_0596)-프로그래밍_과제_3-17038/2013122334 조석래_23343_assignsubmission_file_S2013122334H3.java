import java.util.Scanner;

public class S2013122334H3 {
	private Scanner input = new Scanner(System.in);
	private int n;
	private int l;
	private int r;
	private int result_count;
	private int[] array;
	private int[][] result_array;
	public void init(){
		while(true){
			n = input.nextInt();
			l = input.nextInt();
			r = input.nextInt();
			if(n > 0 && n <= 100){break;}
			else{System.out.print("Àç ÀÔ ·Â = ");}
		}
		System.out.println();
		array = new int[n];
		for(int i = 0; i < array.length; i++){
			array[i] = i + 1;
		}
		result_array = new int[n*(n-1)][n+2];
	}
	public void Array_init(){
		int index = 1;
		for(int i = 0; i < array.length; i++){
			result_array[0][i] = array[i];
		}
		for(int i = 1; i < result_array.length; i++){
			for(int k = 0; k < (result_array[0].length-2); k++){
				if(index != k && index-1 != k){
					result_array[i][k] = result_array[i-1][k];
				}
				else{
					result_array[i][index] = result_array[i-1][index-1];
					result_array[i][index-1] = result_array[i-1][index];
				}
			}
			if(index > (n-2)){index = 1;}
			else{index++;}
		}
	}
	public void left_Calculation(){
		int count = 1;
		int max = result_array[0][0];
		for(int i = 0; i < result_array.length; i++){
			count = 1;
			max = result_array[i][0];
			for(int k = 1; k < (result_array[0].length-2); k++){
				if(result_array[i][k-1] < result_array[i][k]){
					if(max < result_array[i][k]){
						max = result_array[i][k];
						count++;
					}
				}
			}
			result_array[i][n] = count;
		}
	}
	public void right_Calculation(){
		int count = 1;
		int max = result_array[0][array.length-1];
		for(int i = 0; i < result_array.length; i++){
			count = 1;
			max = result_array[i][array.length-1];
			for(int k = (array.length-2); k > -1; k--){
				if(result_array[i][k] > result_array[i][k+1]){
					if(max < result_array[i][k]){
						max = result_array[i][k];
						count++;
					}
				}
			}
			result_array[i][n+1] = count;
		}
	}/*
	public void print(){
		for(int i = 0; i < result_array.length; i++){
			for(int k = 0; k < result_array[0].length; k++){
				System.out.print(result_array[i][k] + " ");
			}
			System.out.println();
		}
	}*/
	public void Result_count(){
		result_count = 0;
		for(int i = 0; i < result_array.length; i++){
			if(result_array[i][result_array[0].length-2] == l && result_array[i][result_array[0].length-1] == r){
				result_count++;
			}
		}
	}
	public int getResult(){return result_count;}
	public int getN(){return n;}
	public static void main(String argv[]){
		S2013122334H3 h3 = new S2013122334H3();
		h3.init();
		h3.Array_init();
		h3.left_Calculation();
		h3.right_Calculation();
		//h3.print();
		h3.Result_count();
		System.out.println(h3.getResult());
	}
}
