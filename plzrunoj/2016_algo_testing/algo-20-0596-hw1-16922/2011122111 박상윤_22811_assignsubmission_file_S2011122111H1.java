import java.util.Scanner;

public class S2011122111H1 {

	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		int n= sc.nextInt();			//n값 받아온다.
		int[] p = new int[n];			//전위 저장할 변수
		int[] b = new int[n];			//후위 저장할 변수
		int[] result;					//결과
		for(int i=0; i<n; i++){			//전위 입력
			p[i]=sc.nextInt();
		}
		for(int i=0; i<n; i++){			//후위 입력
			b[i]=sc.nextInt();
		}		
		result=makemidle(p,b,n);		//중위 만드는 함수		
		for(int i=0; i<n; i++){			//결과 출력
			System.out.print(result[i]+" ");
		}
	}
	static public int[] makemidle(int[] tp, int[] tb,int n){	//중위 만드는 함수
		int[] left, right, ptempl, ptempr, btempl,btempr,result;
		int root =tp[0];					//루트 값
		result=new int[n];					//결과 값 변수
		if(n==1){							//root만 있을 경우
			return tp;
		}
		else{								//root + 알파 //나머지 n-1개에서 left, right 분류
			int i=0;			
			while(tp[1] != tb[i]) i++;		//left 기준이 되는 두번째 루트값으로 기준을 정한다.
			ptempl = new int[i+1];
			btempl = new int[i+1];
			for(int j=0; j<i+1; j++){			//left 값들은 분류
				ptempl[j] = tp[1+j];
				btempl[j] = tb[j];
			}
			left=makemidle(ptempl,btempl,i+1);  //left 값들을 추려내서 다시 중위
			
			
			if(i==n-2){						 	//root,Left만 있을 경우				
				for(int j=0; j<i+1; j++){		//root와 left만 있는 값들로 중위 완성
					result[j]=left[j];
					if(j==i) result[j+1]=root;
				}
				return result;
			}
			
			
			else{								//root,left,right 전부 존재
				ptempr= new int[n-i-2];
				btempr= new int[n-i-2];
				for(int j=0; j<n-i-2; j++){		//rigth 값들은 분류
					ptempr[j]=tp[i+2+j];
					btempr[j]=tb[i+1+j];
				}
				right=makemidle(ptempr,btempr,n-i-2); //right 값들을 중위
				for(int j=0; j<n; j++){			//추려낸 값들을 중위
					if(j<i+1) result[j]=left[j];
					else if(j==i+1) result[j]=root;
					else result[j]=right[j-i-2];
				}
				return result;
			}
		}
	}
	
}
