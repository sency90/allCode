import java.util.Scanner;
public class project1 {
	
	private int inorder[];
	private int s=0;
	private static Scanner s2;
	
	public project1(int number){
		inorder=new int[number]; //���� ��ȸ �迭 �Ҵ�
	}
	
	public static int Inorder(int pre[], int pos[],int num,project1 x){
		int pretmp1[],postmp1[];
		int pretmp2[],postmp2[];
		int presum=0,possum=0;
		int number=0;
		if(num==1){   //�迭ũ�Ⱑ �ϳ���� �ٷ� �װ��� �ְ� ����
			x.inorder[x.s]=pos[0];
			x.s++;
			return 0;
		}
		else if(num==2){ //�迭ũ�Ⱑ �ΰ���� ������ ���ٰ� ��� �� ����
			x.inorder[x.s]=pos[0];
			x.s++;
			x.inorder[x.s]=pos[1];
			x.s++;
			return 0;
		}
			for(int i=0;i<num;i++){  //����,���� �񱳸� ���� ��Ʈ ���� �κ� ����
				presum+=pre[i+1];
				possum+=pos[i];
				if(presum==possum){
					number=i;
					break;
				}
			}
			
		if(number==0){  //��Ʈ ������ 1���� ��� �ٷ� ���� ��ȸ�迭�� �ִ´�
			x.inorder[x.s]=pos[0];
			x.s++;
		}
		else if(number==1){ //��Ʈ ������ 2���� ��� ���� ������� ���� ��ȸ�迭�� �ִ´�
			x.inorder[x.s]=pos[0];
			x.s++;
			x.inorder[x.s]=pos[1];
			x.s++;
			}
		else{ //��Ʈ ������ 3�� �̻��� ��쿡�� ��Ʈ ������ ���θ��� �迭�� ���� �� ����Լ��� ����Ѵ�
			pretmp1=new int[number+1];
			postmp1=new int[number+1];
			for(int i=0;i<number+1;i++){
				pretmp1[i]=pre[i+1];
				postmp1[i]=pos[i];
			}
			Inorder(pretmp1,postmp1,number+1,x);
		}		
		x.inorder[x.s]=pre[0] ; //��Ʈ�� ������ȸ�迭�� �ִ´�
		x.s++;
		if(x.inorder.length==x.s) return 0;  //���� ��ȸ �迭�� ũ�⸸ŭ ������ �������� ������
		if(pre[number+2]==pre[num-1]){  //��Ʈ �������� �������� ������ 
			x.inorder[x.s]=pre[num-1];
			x.s++;
		}
		else if(pre[number+2]!=pre[num-1]){
			pretmp2=new int[num-number-2];
			postmp2=new int[num-number-2];
			for(int i=0;i<num-number-2;i++){
				pretmp2[i]=pre[number+i+2];
				postmp2[i]=pos[number+i+1];
			}
			Inorder(pretmp2,postmp2,num-number-2,x);
		}		
		return 0;
		
	}
	public static void main(String[] args){
		s2 = new Scanner(System.in);
		int Number = s2.nextInt();  //��尹�� �Է�
		int preorder[] = new int[Number]; //���� ��ȸ �迭 �Ҵ�
		int postorder[] = new int[Number]; //���� ��ȸ �迭 �Ҵ�
		project1 x= new project1(Number);
		
		//���� ��ȸ ���� ��ȸ �Է�
		for(int i=0;i<Number;i++)
			preorder[i]=s2.nextInt();
		for(int i=0;i<Number;i++)
			postorder[i]=s2.nextInt();
		//����Լ� ȣ��
		Inorder(preorder,postorder,Number,x);
		
		for(int i=0;i<Number;i++){  //���� ��ȸ ����Ʈ�ϱ�
			System.out.print(x.inorder[i]+" ");
		}
		
	}
	
}
