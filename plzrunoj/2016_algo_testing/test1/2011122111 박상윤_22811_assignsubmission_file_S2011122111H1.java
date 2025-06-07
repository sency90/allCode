import java.util.Scanner;

public class S2011122111H1 {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int n= sc.nextInt();			//n�� �޾ƿ´�.
		int[] p = new int[n];			//���� ������ ����
		int[] b = new int[n];			//���� ������ ����
		int[] result;					//���
		for(int i=0; i<n; i++){			//���� �Է�
			p[i]=sc.nextInt();
		}
		for(int i=0; i<n; i++){			//���� �Է�
			b[i]=sc.nextInt();
		}		
		result=makemidle(p,b,n);		//���� ����� �Լ�		
		for(int i=0; i<n; i++){			//��� ���
			System.out.print(result[i]+" ");
		}
	}
	static public int[] makemidle(int[] tp, int[] tb,int n){	//���� ����� �Լ�
		int[] left, right, ptempl, ptempr, btempl,btempr,result;
		int root =tp[0];					//��Ʈ ��
		result=new int[n];					//��� �� ����
		if(n==1){							//root�� ���� ���
			return tp;
		}
		else{								//root + ���� //������ n-1������ left, right �з�
			int i=0;			
			while(tp[1] != tb[i]) i++;		//left ������ �Ǵ� �ι�° ��Ʈ������ ������ ���Ѵ�.
			ptempl = new int[i+1];
			btempl = new int[i+1];
			for(int j=0; j<i+1; j++){			//left ������ �з�
				ptempl[j] = tp[1+j];
				btempl[j] = tb[j];
			}
			left=makemidle(ptempl,btempl,i+1);  //left ������ �߷����� �ٽ� ����
			
			
			if(i==n-2){						 	//root,Left�� ���� ���				
				for(int j=0; j<i+1; j++){		//root�� left�� �ִ� ����� ���� �ϼ�
					result[j]=left[j];
					if(j==i) result[j+1]=root;
				}
				return result;
			}
			
			
			else{								//root,left,right ���� ����
				ptempr= new int[n-i-2];
				btempr= new int[n-i-2];
				for(int j=0; j<n-i-2; j++){		//rigth ������ �з�
					ptempr[j]=tp[i+2+j];
					btempr[j]=tb[i+1+j];
				}
				right=makemidle(ptempr,btempr,n-i-2); //right ������ ����
				for(int j=0; j<n; j++){			//�߷��� ������ ����
					if(j<i+1) result[j]=left[j];
					else if(j==i+1) result[j]=root;
					else result[j]=right[j-i-2];
				}
				return result;
			}
		}
	}
	
}
