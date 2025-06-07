import java.util.Scanner;
public class S2013122174H1 {
	Scanner s=new Scanner(System.in);
	int []pre;   
	int []post;
	int []rootstack=new int[1000];
	int lpt,rpt,top=-1;

	public S2013122174H1(int leng){
		pre=new int[leng];
		post=new int[leng];
		
		
	}
	public void get_pre(){
		System.out.println("pre_order");
		String pre_s=s.nextLine();
		String []temp=pre_s.split(" ");
		for(int i=0;i<temp.length;i++)
			pre[i]=Integer.parseInt(temp[i]);		
	}
	public void get_post(){       //���� ��ȸ ����� ��Ʈ������ �Է¹ް� " "������ ������ post�迭�� ����
		System.out.println("post_order");
		String pre_s=s.nextLine();
		String []temp=pre_s.split(" ");
		for(int i=0;i<temp.length;i++)
			post[i]=Integer.parseInt(temp[i]);		
	}
	public void in_order(int []pre, int []post){   

		if (post.length<=3){      //post�� ũ�Ⱑ 3�����̸� �������� ������ �ٲ��� 
			if(post.length==3)
				System.out.print(post[0]+" "+post[2]+" "+post[1]+" ");
			else if(post.length==2)
				System.out.print(post[0]+" "+post[1]+" ");
			else if(post.length==1)
				System.out.print(post[0]+" ");			
		}
		else{    
			rootstack[++top]=post[post.length-1];   //lpt�� rpt�� ���ϴ� ����, ������ ���� ���������Ҹ� ��Ʈ��
			for(int i=0;i<pre.length;i++){       //�������� ��Ʈ���� ���������� ���� �ε����� lpt�� ����
				if(pre[i]==rootstack[top]){
					for(int j=0;j<post.length;j++){
						if(pre[i+1]==post[j]){
							lpt=j;
							break;
						}
					}
				break;
				}
			}
			rpt=post.length-2;    //��Ʈ �տ��Ҹ� rpt�� ����
			
			int []left=new int[lpt+1];    //���� ��ȸ �迭�� ��Ʈ ���ʺκа� ������ �κ����� ����
			int []right=new int[rpt-lpt];
			for(int i=0;i<left.length;i++)
				left[i]=post[i];
			
			for(int i=0;i<right.length;i++)
				right[i]=post[i+left.length];
			in_order(pre,left);       //��Ʈ ������ ������ȸ
			System.out.print(rootstack[top--]+" ");  //��Ʈ���� ���
			in_order(pre,right);   //��Ʈ �������� ������ȸ ������ �ǽ���
			
		}
		
	}

	public static void main(String[] args) {
		Scanner s= new Scanner(System.in);
		System.out.println("size");    
		int size=s.nextInt();  //Ʈ���� ũ�⸦ �Է¹���
		S2013122174H1 a=new S2013122174H1(size);
		
		a.get_pre();
		a.get_post();
		System.out.println("in_oreder");
		a.in_order(a.pre, a.post);
		
	}	
}
