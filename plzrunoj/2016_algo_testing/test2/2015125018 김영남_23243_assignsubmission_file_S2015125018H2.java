package S2015125018H2;

import java.util.Scanner;

public class S2015125018H2 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int n; int a = 0;int index=0;
		int answer = 0; int cand_answer=0;
		Scanner s = new Scanner(System.in);
		
		                      //n ����ó��
		n = s.nextInt();                  //n �Է¹ޱ�
			
		int[] arr = new int[n]; 
		int[] arrcount = new int[n]; //x���� ū ���� ����
		
		for(int i=0;i<n;i++){
			arrcount[i] = 0;            //�ʱ�ȭ
		}
		for(int i=0;i<n;i++){
			arr[i] = s.nextInt();            //���� �ޱ�
		}
		
		int notneed = 10000;
		for(int i = 0;i < n;i++){                
			if(notneed < arr[i]){
				continue;
			}
			for(int j = 0;j < n;j++){
				if(arr[i] <=arr[j] ){
					arrcount[i]++;
				}
			}
			if(arrcount[i] < arr[i]){
				notneed = arr[i];
			}else{
				cand_answer = arr[i];
				if(answer < cand_answer){
					answer = cand_answer;
				}
				if(arrcount[i] == arr[i]){
					a = 1;
					index = i;
					break;
				}
			}
		}	
		
		
		if(a == 1){
			System.out.println(arr[index]);
		}else{
			System.out.println(answer);
		}
		

	}

}
