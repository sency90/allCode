import java.util.Scanner;

public class S2015125018H1 {
	int rout = 0;
	static int find = 0;
	
	static int Inorder(int[] pre,int[] post,int[] in,int n){	
		int[] prearr = pre;
		int[] postarr =post;
		
		int[] leftprearr;
		int[] rightprearr;
		int[] leftpostarr;
		int[] rightpostarr;
		int exfind = find;
		for(int j=0;j<n;j++){
			if(pre[1] == post[j]){
				find = j;
				leftprearr = new int[1000];
				leftpostarr = new int[1000];
				rightprearr = new int[1000];
				rightpostarr = new int[1000];
				for(int k=exfind+1;k<=find;k++){
					in[k]=postarr[k];  //왼쪽트리 넣어주기
					leftprearr[k] = prearr[k+1];
					leftpostarr[k] = postarr[k];
				}
				in[find+1] = prearr[0];   //루트 넣어주기
				for(int k=find+2;k<n;k++){     //오른쪽 트리 넣어주기
					in[exfind+1] = postarr[k-1];
					rightprearr[k-find-2] = prearr[k]; 
					rightpostarr[k-find-2] = postarr[k-1];
				}
				if(rightprearr.length==1 && leftprearr.length==1){
					for(int k=0;k<in.length;k++){
						System.out.print(in[k]);
						System.out.print(" ");
					}
					return 0;
				}else if(rightprearr.length==1){
					Inorder(leftprearr,leftpostarr,in,find+1); //왼쪽트리 재귀
				}else if(leftprearr.length==1){
					Inorder(rightprearr,rightpostarr,in,n-find-2);//오른쪽트리 재귀
				}else{
					Inorder(leftprearr,leftpostarr,in,find+1);
					Inorder(rightprearr,rightpostarr,in,n-find-2);
				}
			}
		}
		for(int k=0;k<in.length;k++){
			System.out.print(in[k]);
			System.out.print(" ");
		}
		return 0;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner s = new Scanner(System.in);		
		int n;
		n = s.nextInt();
		int[] prearr = new int[n];
		int[] postarr = new int[n];
		int[] inarr = new int[n];
		//int[] inarr = new int[n];
		for(int i = 0;i<n;i++){
			prearr[i] = s.nextInt();
		}
		for(int i = 0;i<n;i++){
			postarr[i] = s.nextInt();
		}
		Inorder(prearr,postarr,inarr,n);
		return;
	}
}