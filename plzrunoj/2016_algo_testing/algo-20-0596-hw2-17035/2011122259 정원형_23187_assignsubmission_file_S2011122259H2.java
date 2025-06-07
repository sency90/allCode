import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class S2011122259H2 {
	public static void main(String args[]){
		Scanner in = new Scanner(System.in);
		int max = in.nextInt();
		Integer[] input = new Integer[max];
		for (int i = 0; i <max ; i++) {
			input[i] = in.nextInt();
		}
		  Arrays.sort(input, Collections.reverseOrder());

		  for(int i=0; i<max; i++){
			  if(input[i] > i+1){
				  input[i] = null;
			  }
		  }
		  for(int i=0; i<max; i++){
			  if( input[i] != null){
				  System.out.println(input[i]);
				  break;
			  }
		  }
	}
}
