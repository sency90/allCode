package algori;

import java.util.Arrays;
import java.util.Scanner;

public class cnt_numbers {
	public static void main(String[] args) {
		int i,n,num=-1;
		
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		sc.nextLine();//버퍼지우기
		
		String [] str = new String [n];
		int [] nums = new int[n];
		
		str =  sc.nextLine().split(" ");
		for (i=0;i<n;i++){
			nums[i] = Integer.parseInt(str[i]);
		}
		Arrays.sort(nums); //너무 편하다아!
		
		for(i=0;i<n;i++){
			if(num!=nums[i]){
				if(n-i<nums[i]){
					System.out.println(num);
					return;
				}
				num=nums[i];
			}
		}
		System.out.println(num);
		return;
	}
}
