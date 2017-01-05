#include <cstdio>
#include <stdio.h>

using namespace std;

	static long long save[101][101][101];
	
	static long long D(int n, int l, int r){
		
		if(l == 1 && r == 1) {
		      if(n == 1) {
		         return 1;
		      } else {
		         return 0;
		      }
		   } 
		   
		   if(l < 1 || r < 1 || l + r > n + 1) {
		      return 0;
		   }
		   
		   if(save[n][l][r]!=-1) {
		      return save[n][l][r];
		   } else {
		      return save[n][l][r] = ((n - 2) * D(n - 1, l, r) 
		    		  + D(n - 1, l - 1, r) + D(n - 1, l, r -1))%1000000007;
		      
		   }
	
	}
	int main() {
		// TODO Auto-generated method stub
		int n, l, r;
		scanf("%d%d%d", &n, &l, &r);

		for(int i=0; i<=n; i++){
			for(int j=0; j<=n; j++){
				for(int u=0; u<=n; u++){
					save[i][j][u]=-1;
				}
			}
		}
		long a=1000000007;
		printf("%lld\n", D(n,l,r));
	}


