import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class S2008122007H2 
{
    public static void main(String args[]) throws IOException {
    	
    	int size;
    	Scanner put = new Scanner(System.in);
    	System.out.print("정수 개수 입력 (1~1000) : ");
    	size = put.nextInt();
		 
        int a[] = new int[size];
        int b[] = new int[size];
        
        System.out.printf("정수 입력 : ");
       
        InputStreamReader r1 = new InputStreamReader(System.in);
        BufferedReader b1 = new BufferedReader(r1);
        String num = b1.readLine();
        
        String[] slice1 = num.split(" ");
        
        for(int i = 0; i <= size-1; i++){
             a[i] = Integer.parseInt(slice1[i]);
            }
            
        int count = 0;
        ArrayList<Integer> list = new ArrayList<Integer>();
   
        for(int m = 0; m <= size-1; m++){
        	for(int n = 0; n <= size-1; n++){
        		if(a[m] <= a[n]){
        			count++;
        			}
        		}
        	if(a[m] <= count){
        		list.add(a[m]);
        		}
        	count = 0;
        }   
        Integer answer = Collections.max(list);
        System.out.print("가장 큰 수는 " + answer);   
    }
}
