import java.util.Arrays;
import java.util.Scanner;

public class S2013122174H2 {
	int []num;
	Scanner s=new Scanner(System.in);
	public S2013122174H2(int n){	   	
		num=new int[n];
		
	}
	public void get_num(){         
		
		String num_s=s.nextLine();
		String []temp=num_s.split(" ");
		for(int i=0;i<temp.length;i++)
			num[i]=Integer.parseInt(temp[i]);		
	}
	public int find_x(){
		Arrays.sort(num);
		int top=0;
		int []ok=new int[num.length];
		for(int i=0;i<num.length;i++){
			if (num[i]<=num.length-i)
				ok[top++]=num[i];
		}
		if(top==0)
			return -1;
		else
			return ok[--top];
	}
	public static void main(String[] args) {
		Scanner s=new Scanner(System.in);
		int n=s.nextInt();
		S2013122174H2 a=new S2013122174H2(n);
		a.get_num();
		System.out.println(a.find_x());
		

	}

}
