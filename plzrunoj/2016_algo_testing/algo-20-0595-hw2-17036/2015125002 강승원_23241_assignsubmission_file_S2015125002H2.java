import java.util.Arrays;
import java.util.Scanner;
public class S2015125002H2 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		int len = s.nextInt();
		int j;
		s.nextLine();
		String front_str = s.nextLine();
		String[] temp;

		int[] list = new int[len];
		temp = front_str.split(" ");
		for (int i = 0; i < len; i++)
			list[i] = (Integer.parseInt(temp[i]));
		Arrays.sort(list);
		
		for ( j=len-1;j>=0;j--)
			if(len-j>=list[j]) break;
		System.out.print(list[j]);
		return;
	}
}