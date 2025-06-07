package a;
import java.util.Scanner;
import java.math.*;
import java.util.Random;
public class S2015125037list {
      public static void main( String argv[])
      {
    	  Scanner number = new Scanner(System.in);
    	  int n = number.nextInt();
    	  int num = 0;
    	  int A[] = new int [1000];
    	  int B[] = new int[1000];
    	
      
    	  Scanner scan = new Scanner(System.in);
    	
    	  for(int i = 0 ; i<n; i++ )
    	  {
    		//  System.out.println(1);
    		  A[i] = scan.nextInt();
    	  }
       for(int i = 0; i<n; i++)
       {
        for(int j = 0; j<n; j++)
        {
        	int maxVal = Math.min(A[i], A[j]);
        	int minVal = Math.max(A[i], A[j]);
        	A[i] = minVal;
        	A[j] = maxVal;
        }
       } 
       for(int i = 0; i<n; i++)
       {
    	   //System.out.println(A[i]);
    	   if(A[i] <= n-i+1)
    	   {
    		   B[num]= A[i];
         
    	   }
       }
       number.close();
       scan.close();
       System.out.println(B[num]);
       
       
      }
}
 