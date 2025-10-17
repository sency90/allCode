package algho;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;


public class S2015125068H1 {

    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner s = new Scanner(System.in);
        S2015125068H1 a = new S2015125068H1();
        int size=s.nextInt();
        ArrayList pre=new ArrayList(size);
        ArrayList post=new ArrayList(size);
        ArrayList check=new ArrayList(size);
        ArrayList result=new ArrayList(size);

        for(int i=0; i<size; i++){
            pre.add(s.nextInt());
        }
        for(int i=0; i<size; i++){
            post.add(s.nextInt());
        }
        for(int i=0; i<size; i++){
        	check.add(i+1);
        }
        
        
        for(int i=0; i<size; i++){
        	Object key=post.get(i);//////
        	int k_index=pre.indexOf(key);
        	if(k_index==0){
        		break;
        	}
        	Object b_key=pre.get(k_index-1);
        	
        	
        	if(i==0||check.indexOf(pre.get(k_index-1))!=-1||check.indexOf(key)!=-1){
        		if(check.indexOf(key)!=-1){
        			check.set(check.indexOf(key), 0);
        			result.add(key);
        		}
        		if(check.indexOf(b_key)!=-1){
        			check.set(check.indexOf(b_key), 0);
        			result.add(b_key);
        			
        		}
        		
        	}
 
        }for(int i=0; i<size; i++){
        	System.out.printf("%d ", result.get(i));
        }

    }
}