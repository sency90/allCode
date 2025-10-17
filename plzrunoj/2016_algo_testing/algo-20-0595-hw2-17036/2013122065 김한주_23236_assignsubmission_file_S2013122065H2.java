import java.util.Scanner;
public class project1 {
	private static Scanner s2;
	
	static void caculation(int numbers[], int num){
		int numcount[] = new int[num];
	
		for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
				if(numbers[i] <= numbers[j])
					numcount[i]++;
				else ;
			}
		}
		for(int i=0;i<num;i++){
			for(int j=0;j<num;j++){
				if(numcount[i]>numcount[j]){
					int tmp=0;
					tmp = numcount[i];
					numcount[i] = numcount[j];
					numcount[j] = tmp;
					tmp = numbers[i];
					numbers[i] = numbers[j];
					numbers[j] = tmp;				
				}
				else ;
			}
		}
		
		 for(int i=0;i<num;i++){
			 if((numcount[i]>=numbers[i]) && (numbers[0] < numbers[i]))
				 numbers[0] = numbers[i];
		 }
		 System.out.print(numbers[0]);
		
	}
	public static void main(String[] args){
		s2 = new Scanner(System.in);
		int number = s2.nextInt();  //°¹¼ö ÀÔ·Â
		int Numbers[] = new int[number];
		
		for(int i=0;i<number;i++)
			Numbers[i]=s2.nextInt();	
		caculation(Numbers,number);
	}
	
}
