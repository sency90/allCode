package h2;

import java.util.*;

public class S2012122374H2 {

	
	public static void calc(int num, int[] value){
		
		int[] map = new int[num];
		int max = 0;
		int index = 0;
		int cnt = 0;
		
		
		//mapping cnt
		for(int i=0; i<num; i++) {
			for(int j=0; j<num; j++){
				if(value[i] <= value[j])
					cnt++;		
			}
			map[i] = cnt;
			cnt = 0;
		}
		
		for(int i=0; i<num; i++) {
			
			if(value[i] <= map[i]){
				if(max < value[i])
					max = value[i];
			}
				
			
		}
		
		System.out.println(max);
		
		
		
			
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner scan = new Scanner(System.in);
		int cnt = 0;
		
		while(cnt<3){
		
			int num = scan.nextInt();
			int[] value = new int[num];
			
			if(!(0 <= num && num <= 1000))
				System.exit(0);
			
			else
				for(int i=0; i<num; i++) {
					value[i] = scan.nextInt();
					if(!(0 <= value[i] && value[i] <= 10000)){
							System.out.println("입력값 오류");
							System.exit(0);
					}
				}
			
			calc(num, value);
			
			
			cnt++;
		}
	
				
		

	}

}
