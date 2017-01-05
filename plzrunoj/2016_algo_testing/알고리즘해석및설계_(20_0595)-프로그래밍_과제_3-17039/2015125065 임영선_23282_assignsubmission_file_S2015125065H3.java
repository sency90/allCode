package algori;

import java.util.Scanner;

public class building_cnt {
	static int cnt=0,n,l,r;
	
	public static void main(String[] args) {
		int i;
		int [] building;
		boolean [] pro;
		
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		l = sc.nextInt();
		r = sc.nextInt();
		
		pro = new boolean [n];
		building = new int [n];
		for(i=0;i<n;i++){
			pro[i]=true;
		}
		
		subf(pro,0,building);

		System.out.println(cnt%1000000007);
	}
	
	static void subf(boolean [] pro,int build,int [] building){
		int i;
		
		if(build==n){
			/*
			for(int j=0;j<build;j++){
				System.out.print(building[j]+" ");
			}
			System.out.println("");
			*/
			int l_hight=0,r_hight=0,l_cnt=0,r_cnt=0;
			for(i=0;i<n;i++){
				if(building[i]>l_hight){
					l_cnt++;
					l_hight=building[i];
				}
			}
			i--;
			for(;i>-1;i--){
				if(building[i]>r_hight){
					r_cnt++;
					r_hight=building[i];
				}
			}
			
			if(l==l_cnt && r==r_cnt){
				cnt+=1;
			}
			return;
		}
		
		for(i=0;i<n;i++){
			boolean [] s_pro = new boolean[n];
			System.arraycopy( pro, 0, s_pro, 0, pro.length);
			
			if(pro[i]==true){
				s_pro[i]=false;
				building[build]=i+1;
				subf(s_pro,build+1,building);
			}
		}
	}
}
//https://code.google.com/codejam/contests.html
//±¦ÂúÀº »çÀÌÆ®! ÄÚµå¢w! ¾Ë°íÀÖ´Ù¸é ½Ã¹«·è..
