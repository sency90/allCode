package S2015125054H1;
import java.util.Scanner;
import java.util.ArrayList;
public class S2015125054H1 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int ch1 =-1;
		int z =0;
		int n;
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
		ArrayList pre = new ArrayList(n);
		ArrayList pro = new ArrayList(n);
		ArrayList ino = new ArrayList(n);
		for(int i=0;i<n;i++){
			z =sc.nextInt();
			pre.add(z);
		}
		for(int i=0;i<n;i++){
			z =sc.nextInt();
			pro.add(z);
		}
		for(int i=0;i<n;i++){
			ch1 = pre.indexOf(pro.get(i));
			if(ino.indexOf(pro.get(i))==-1){
				ino.add(pre.get(ch1));
			}
			if(ch1==0){
				continue;
			}
			if(ino.indexOf(pre.get(ch1-1))==-1){
				ino.add(pre.get(ch1-1));
			}
		}
		System.out.println(ino);
	    }
}