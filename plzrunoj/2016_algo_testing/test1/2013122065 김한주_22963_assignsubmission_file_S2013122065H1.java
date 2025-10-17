import java.util.Scanner;
public class project1 {
	
	private int inorder[];
	private int s=0;
	private static Scanner s2;
	
	public project1(int number){
		inorder=new int[number]; //중위 순회 배열 할당
	}
	
	public static int Inorder(int pre[], int pos[],int num,project1 x){
		int pretmp1[],postmp1[];
		int pretmp2[],postmp2[];
		int presum=0,possum=0;
		int number=0;
		if(num==1){   //배열크기가 하나라면 바로 그값을 넣고 리턴
			x.inorder[x.s]=pos[0];
			x.s++;
			return 0;
		}
		else if(num==2){ //배열크기가 두개라면 후위랑 같다고 계산 후 리턴
			x.inorder[x.s]=pos[0];
			x.s++;
			x.inorder[x.s]=pos[1];
			x.s++;
			return 0;
		}
			for(int i=0;i<num;i++){  //중위,후위 비교를 통해 루트 왼쪽 부분 추출
				presum+=pre[i+1];
				possum+=pos[i];
				if(presum==possum){
					number=i;
					break;
				}
			}
			
		if(number==0){  //루트 왼쪽이 1개인 경우 바로 중위 순회배열에 넣는다
			x.inorder[x.s]=pos[0];
			x.s++;
		}
		else if(number==1){ //루트 왼쪽이 2개인 경우 후위 순서대로 중위 순회배열에 넣는다
			x.inorder[x.s]=pos[0];
			x.s++;
			x.inorder[x.s]=pos[1];
			x.s++;
			}
		else{ //루트 왼쪽이 3개 이상인 경우에는 루트 왼쪽을 새로만든 배열에 넣은 후 재귀함수를 사용한다
			pretmp1=new int[number+1];
			postmp1=new int[number+1];
			for(int i=0;i<number+1;i++){
				pretmp1[i]=pre[i+1];
				postmp1[i]=pos[i];
			}
			Inorder(pretmp1,postmp1,number+1,x);
		}		
		x.inorder[x.s]=pre[0] ; //루트를 중위순회배열에 넣는다
		x.s++;
		if(x.inorder.length==x.s) return 0;  //중위 순회 배열의 크기만큼 내용이 차있을때 끝내기
		if(pre[number+2]==pre[num-1]){  //루트 오른쪽이 존재하지 않을때 
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
		int Number = s2.nextInt();  //노드갯수 입력
		int preorder[] = new int[Number]; //전위 순회 배열 할당
		int postorder[] = new int[Number]; //후위 순회 배열 할당
		project1 x= new project1(Number);
		
		//전위 순회 후위 순회 입력
		for(int i=0;i<Number;i++)
			preorder[i]=s2.nextInt();
		for(int i=0;i<Number;i++)
			postorder[i]=s2.nextInt();
		//재귀함수 호출
		Inorder(preorder,postorder,Number,x);
		
		for(int i=0;i<Number;i++){  //중위 순회 프린트하기
			System.out.print(x.inorder[i]+" ");
		}
		
	}
	
}
