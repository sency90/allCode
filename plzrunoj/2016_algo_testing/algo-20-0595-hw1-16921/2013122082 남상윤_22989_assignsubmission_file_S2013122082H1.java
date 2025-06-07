package schoolAlgorithm;

import java.util.Scanner;

public class S2013122082H1 {

	static int a[] = {0, };	//������ȸ
	static int b[] = {0, };	//������ȸ
	
	public static boolean check(int a[], int b[]) //������ȸ�� ������ȸ�� ������ ��
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
	
	public static void middle(int a[], int b[], int n)	//����
	{
		if(check(a,b)==false)
		{
			int root = a[0];	//���������� �Ǿ��� ��Ʈ
			int firstleftroot = a[1];	//���������� ��Ʈ������ �����ڽ��� ��Ʈ
			int firstrightroot=0;	//���������� �������ڽ��� ��Ʈ
			int lastleftroot = 0;	//���������� �����ڽ��� ��Ʈ
			int lastrightroot= b[n-2];	//���������� ��Ʈ
			
			for(int i=0; i<n-1; i++)	//���������� �����ڽİ� �������� ������������ ã��
			{
				if(b[i] == a[1])
				{				
					lastleftroot = i;
				}
			}
			
			for(int i=0; i<n-1;i++)	//���������� ������ �ڽİ� ���� ���� ������������ ã��
			{
				if(a[i]==b[n-2])
				{
					firstrightroot = i;
				}
			}
			
			if(lastleftroot ==0 || firstrightroot==0)	//��尡 �ϳ��� ���
			{
				System.out.printf("%d %d %d ", a[1], root, b[n-2]);				
			}
			
			else if(lastleftroot!=0 && firstrightroot!=0)	//�ϳ��� �ƴ϶��
			{			
				int d[] = new int[lastleftroot];	//���� �ڽ��� ��������
				int e[] = new int[lastleftroot];	//���� �ڽ��� ��������
				int f[] = new int[n-firstrightroot];	//������ �ڽ��� ��������
				int g[] = new int[n-firstrightroot];	//������ �ڽ��� ��������
				
				for(int i=0; i<lastleftroot; i++)	//�����ڽ��� ���� �迭
				{
					d[i] = a[i+1];
					e[i] = b[i];				
				}
					
				for(int i=0; i<n-1-firstrightroot; i++)	//������ �ڽ��� ���� �迭
				{
					f[i] = a[firstrightroot+i];
					g[i] = b[n-2-lastleftroot+i];
				}
				
				
				
				middle(d,e,lastleftroot);	//���ʿ��ѹ�
				System.out.printf("%d ", root);	//��Ʈ���
				middle(f,g,n-1-firstrightroot);	//�����ʿ� �ѹ�
				
			}
		}
	}
	
	int[] readData(int n) //���������� ���������� �Է¹޴� ��
	{ 
	      Scanner sc = new Scanner(System.in); 
	      int[] list;
	      list = new int[n];// n�� ũ�⸦ ���� �迭�� ���� 
	      for (int i = 0; i < list.length; i++) 
	      list[i] = sc.nextInt();// �� �迭�� �ε����� �Էµ� ���ڸ� ���� 
	      return list; 
	   }  
	
	public static void main(String[] args) 
	{		
		Scanner sc = new Scanner(System.in);
		
		S2013122082H1 at = new S2013122082H1();
		int n = 0;
		String m;
		
		System.out.println("����� ������ �Է��� �ּ���.");
		n=sc.nextInt();
		m=sc.nextLine();
		
		System.out.println("������ȸ�� ����� �Է��� �ּ���");
		a=at.readData(n);
			
		System.out.println("������ȸ�� ����� �Է��� �ּ���");
		b=at.readData(n);
			
		System.out.println("������ȸ�� �����");
		middle(a,b,n);	
	}
}
