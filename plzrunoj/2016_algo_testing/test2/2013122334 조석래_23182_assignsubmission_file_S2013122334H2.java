package Two_2013122334;

import java.util.Scanner;

public class S2013122334H2 {
	private int n;
	private int[] in_num;
	private int[] in_index;
	private Scanner input = new Scanner(System.in);
	private int count;
	private int index;
	private int result_r;
	public two_2013122334(int n){this.n = n;}
	public void input(){
		in_num = new int[n];
		in_index = new int[n];
		for(int i = 0; i < n; i++){
			in_num[i] = input.nextInt();
		}
	}
	public void count_method(){
		count = 0;
		for(int i = 0; i < n; i++){
			for(int k = 0; k < n; k++){
				if(in_num[i] <= in_num[k]){
					count++;
				}
			}
			in_index[i] = count;
			count = 0;
		}
	}
	public void result(){
		index = 0;
		result_r = 0;
		for(int i = 0; i < n; i++){
			if(in_num[i] <= in_index[i]){
				if(in_num[index] > result_r){
					index = i;
					result_r = in_num[index];
				}
			}
		}
	}
	public int getresult_r(){return result_r;}
	public static void main(String argv[]){
		Scanner input = new Scanner(System.in);
		int n = 0;
		// n입력
		while(true){
			n = input.nextInt();
			if(n < 1000 && n >= 1){break;}
			else{System.out.println("Reinput");}
		}
		// 정수의 숫자
		two_2013122334 two = new two_2013122334(n);
		two.input();
		two.count_method();
		two.result();
		System.out.println(two.getresult_r());
	}
}
