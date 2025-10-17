package S2015125054H2;
import java.util.Scanner;
public class S2015125054H2 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n;
		int ch=0;
		int ch1 =0;
		int chf =0;
		while(true){
			n = sc.nextInt();
			if(n<1){
				System.out.println("again");
				continue;
			}else if(n>1000){
				System.out.println("again");
				continue;
			}else{
				break;
			}
		}
		int list[]=new int[n];
		for(int i=0;i<n;i++){
			list[i] =sc.nextInt();
			if(list[i]>10000){
				i--;
				continue;
			}else if(list[i]<0){
				i--;
				continue;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(list[i]<=list[j]){
					ch++;
				}if(ch>=list[i]){
					ch1=list[i];
				}
			}
			ch=0;
			if(ch1>chf){
				chf = ch1;
			}
		}
		System.out.println(chf);
	}
}
