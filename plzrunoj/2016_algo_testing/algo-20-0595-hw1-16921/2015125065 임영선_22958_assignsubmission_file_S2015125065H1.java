package algori;

import java.util.Scanner;

public class visite {
	static int n,m=0;
	static boolean first = true;
	
	static String [] f_tree;
	static String [] b_tree;
	static String [] m_tree;

	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		sc.nextLine();//버퍼지우기
		
		f_tree = new String [n];
		b_tree = new String [n];
		m_tree = new String [n];
		
		f_tree = sc.nextLine().split(" ");
		b_tree = sc.nextLine().split(" ");
		
		if(n==1){
			System.out.print(f_tree[0]);
		}
		
		subtree(f_find(b_tree[0]));
		
		for(m=0;m<n-1;m++){
			System.out.print(m_tree[m] + " ");
		}
		System.out.println(m_tree[m]);
	}
	
	static void subtree(int start){
		int b_f;
		
		if(m==n){//-1끝난 경우
			return;
		}
		
		b_f = b_find(f_tree[start-1]);
		if(b_f==1){
			b_remove(0);
			f_remove(start);
			subtree(start-1);
			return;
		}
		
		if(first){
			first=false;
			m_tree[m++]=b_tree[0];
		}
		m_tree[m++] = b_tree[b_f];
		
		f_remove(f_find(b_tree[0]));
		b_remove(0);
		
		if(b_f==2){
			m_tree[m++] = b_tree[0];
			f_remove(f_find(b_tree[0]));
			b_remove(0);
			
			subtree(start-1);
			return;
			
		}else{
			first=true;
			subtree(f_find(b_tree[0]));
			return;
		}
	}
	
	static int f_find(String spell){
		int i;
		for (i=0;i<n;i++){
			if(f_tree[i].equals(spell)){
				return i;
			}
		}
		return i;
	}
	static int b_find(String spell){
		int i;
		for (i=0;i<n;i++){
			if(b_tree[i].equals(spell)){
				return i;
			}
		}
		return i;
	}
	static void b_remove(int loc){
		for (;loc<n-1;loc++){
			b_tree[loc]= b_tree[loc+1];
		}
		b_tree[loc] = "0"; 
	}
	static void f_remove(int loc){
		for (;loc<n-1;loc++){
			f_tree[loc]= f_tree[loc+1];
		}
		f_tree[loc] = "0"; 
	}
}
