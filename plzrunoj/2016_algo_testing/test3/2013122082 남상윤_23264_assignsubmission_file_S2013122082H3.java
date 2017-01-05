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
	
	
	//������ ����
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
		
		System.out.println("������ ������ �Է��Ͻÿ�");
		n = sc.nextInt();
		m = sc.nextLine();
		
		System.out.println("���ʿ��� �������� ���̴� ������ ���� �Է��Ͻÿ�");
		lef = sc.nextInt();
		m = sc.nextLine();
		
		System.out.println("�����ʿ��� �������� ���̴� ������ ���� �Է��Ͻÿ�");
		rig = sc.nextInt();
		m = sc.nextLine();
		
		//1�� �ְ�, ���ʿ� �ѹ��� 2�� ����- ����Ǽ� 2��
		//���� ����Ǽ� 2���� ó�� �߰� ���� 3�� ���� - 6��
		
	
		a[0] = 1;
		
		System.out.printf("%d", a[0]);
		build(n, lef, rig);
		
		
	}

}
