package schoolAlgorithm;

import java.util.Scanner;

public class S2013122082H1 {

	static int a[] = {0, };	//전위순회
	static int b[] = {0, };	//후위순회
	
	public static boolean check(int a[], int b[]) //전위순회와 후위순회가 같은지 비교
	{
		for(int i=0; i<a.length;i++)
		{
			if(a[i] != b[i])
			{
				return false;
			}
		}
		
		return true;
	}
	
	public static void middle(int a[], int b[], int n)	//정렬
	{
		if(check(a,b)==false)
		{
			int root = a[0];	//전위순위의 맨앞은 루트
			int firstleftroot = a[1];	//전위순위의 루트다음은 왼쪽자식의 루트
			int firstrightroot=0;	//전위순위의 오른쪽자식의 루트
			int lastleftroot = 0;	//후위순위의 왼쪽자식의 루트
			int lastrightroot= b[n-2];	//후위순위의 루트
			
			for(int i=0; i<n-1; i++)	//전위순위의 왼쪽자식과 같은값을 후위순위에서 찾음
			{
				if(b[i] == a[1])
				{				
					lastleftroot = i;
				}
			}
			
			for(int i=0; i<n-1;i++)	//후위순위의 오른쪽 자식과 같은 값을 전위순위에서 찾음
			{
				if(a[i]==b[n-2])
				{
					firstrightroot = i;
				}
			}
			
			if(lastleftroot ==0 || firstrightroot==0)	//노드가 하나면 출력
			{
				System.out.printf("%d %d %d ", a[1], root, b[n-2]);				
			}
			
			else if(lastleftroot!=0 && firstrightroot!=0)	//하나가 아니라면
			{			
				int d[] = new int[lastleftroot];	//왼쪽 자식의 전위순위
				int e[] = new int[lastleftroot];	//왼쪽 자식의 후위순위
				int f[] = new int[n-firstrightroot];	//오른쪽 자식의 전위순위
				int g[] = new int[n-firstrightroot];	//오른쪽 자식의 후위순위
				
				for(int i=0; i<lastleftroot; i++)	//왼쪽자식을 넣은 배열
				{
					d[i] = a[i+1];
					e[i] = b[i];				
				}
					
				for(int i=0; i<n-1-firstrightroot; i++)	//오른쪽 자식을 넣은 배열
				{
					f[i] = a[firstrightroot+i];
					g[i] = b[n-2-lastleftroot+i];
				}
				
				
				
				middle(d,e,lastleftroot);	//왼쪽에한번
				System.out.printf("%d ", root);	//루트출력
				middle(f,g,n-1-firstrightroot);	//오른쪽에 한번
				
			}
		}
	}
	
	int[] readData(int n) //전위순위와 후위순위를 입력받는 곳
	{ 
	      Scanner sc = new Scanner(System.in); 
	      int[] list;
	      list = new int[n];// n의 크기를 가진 배열을 생성 
	      for (int i = 0; i < list.length; i++) 
	      list[i] = sc.nextInt();// 각 배열의 인덱스에 입력된 숫자를 넣음 
	      return list; 
	   }  
	
	public static void main(String[] args) 
	{		
		Scanner sc = new Scanner(System.in);
		
		S2013122082H1 at = new S2013122082H1();
		int n = 0;
		String m;
		
		System.out.println("노드의 갯수를 입력해 주세요.");
		n=sc.nextInt();
		m=sc.nextLine();
		
		System.out.println("전위순회의 결과를 입력해 주세요");
		a=at.readData(n);
			
		System.out.println("후위순회의 결과를 입력해 주세요");
		b=at.readData(n);
			
		System.out.println("중위순회의 결과는");
		middle(a,b,n);	
	}
}
