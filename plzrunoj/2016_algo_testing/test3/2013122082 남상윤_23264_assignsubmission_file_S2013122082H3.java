package schoolAlgorithm;

import java.util.Scanner;

public class S2013122082H3
{
	static int a[] = new int[1000];
	static int b[] = new int[1000];
	static int count = 1;
	static int ans = 0;
	
	//0~i i i+1~n
	
	static void build(int n, int lef, int rig)
	{
		int c=0;
		
		for(int i=0; i<count; count++)
		{
			
			for(int j=0; j<c; j++)
			{
				b[j] = a[j];
			}
			
			b[c] = count;
			
			for(int j=c+1; j<n; j++)
			{
				b[j] = a[j];
			}
			
			int p=b[0];
			int q=0;
			
			for(int x=1; x<n; x++)
			{
				if(p<b[x])
				{
					q++;
					p=b[x];
				}	
			}
			
			int r=b[n];
			int s=0;
			
			for(int x=n; x>0; x--)
			{
				if(p<b[x])
				{
					q++;
					p=b[x];
				}	
			}
		
			if(q==lef && r ==rig)
				ans++;
			
			c++;
		}
		
		for(int i=0; i<n+1; i++)
		System.out.printf("%d", b[i]);
		
	}
	
	
	//빌딩의 높이
	public static void main(String[] args) 
	{
		
		Scanner sc = new Scanner(System.in);
		int num = 0;
		int n;
		int lef;
		int rig;
		int lcount =0;
		int rcount = 0;
		
		String m;
		
		System.out.println("빌딩의 갯수를 입력하시오");
		n = sc.nextInt();
		m = sc.nextLine();
		
		System.out.println("왼쪽에서 보았을때 보이는 빌딩의 수를 입력하시오");
		lef = sc.nextInt();
		m = sc.nextLine();
		
		System.out.println("오른쪽에서 보았을때 보이는 빌딩의 수를 입력하시오");
		rig = sc.nextInt();
		m = sc.nextLine();
		
		//1개 있고, 양쪽에 한번씩 2를 넣음- 경우의수 2개
		//위의 경우의수 2개에 처음 중간 끝에 3을 넣음 - 6개
		
	
		a[0] = 1;
		
		System.out.printf("%d", a[0]);
		build(n, lef, rig);
		
		
	}

}
