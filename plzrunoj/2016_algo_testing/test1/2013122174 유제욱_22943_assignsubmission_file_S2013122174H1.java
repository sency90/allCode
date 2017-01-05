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
	public void get_post(){       //후위 순회 결과를 스트링으로 입력받고 " "단위로 나누어 post배열에 저장
		System.out.println("post_order");
		String pre_s=s.nextLine();
		String []temp=pre_s.split(" ");
		for(int i=0;i<temp.length;i++)
			post[i]=Integer.parseInt(temp[i]);		
	}
	public void in_order(int []pre, int []post){   

		if (post.length<=3){      //post의 크기가 3이하이면 수동으로 순서를 바꿔줌 
			if(post.length==3)
				System.out.print(post[0]+" "+post[2]+" "+post[1]+" ");
			else if(post.length==2)
				System.out.print(post[0]+" "+post[1]+" ");
			else if(post.length==1)
				System.out.print(post[0]+" ");			
		}
		else{    
			rootstack[++top]=post[post.length-1];   //lpt와 rpt를 정하는 과정, 후위의 제일 마지막원소를 루트로
			for(int i=0;i<pre.length;i++){       //전위에서 루트원소 다음원소의 후위 인덱스를 lpt로 지정
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
			rpt=post.length-2;    //루트 앞원소를 rpt로 지정
			
			int []left=new int[lpt+1];    //후위 순회 배열을 루트 왼쪽부분과 오른쪽 부분으로 나눔
			int []right=new int[rpt-lpt];
			for(int i=0;i<left.length;i++)
				left[i]=post[i];
			
			for(int i=0;i<right.length;i++)
				right[i]=post[i+left.length];
			in_order(pre,left);       //루트 왼쪽의 중위순회
			System.out.print(rootstack[top--]+" ");  //루트원소 출력
			in_order(pre,right);   //루트 오른쪽의 중위순회 순으로 실시함
			
		}
		
	}

	public static void main(String[] args) {
		Scanner s= new Scanner(System.in);
		System.out.println("size");    
		int size=s.nextInt();  //트리의 크기를 입력받음
		S2013122174H1 a=new S2013122174H1(size);
		
		a.get_pre();
		a.get_post();
		System.out.println("in_oreder");
		a.in_order(a.pre, a.post);
		
	}	
}
