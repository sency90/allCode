#include<iostream> 
#include<cstdio>

using namespace std; 

long long d[101][101][101]; 
long long mod = 1000000007LL; 

int main() { 
    int N, L, R; 
    cin >> N >> L >> R; 
 
   d[1][1][1] = 1LL; 

    for (int i=2; i<=N; i++) { 
         for (int j=1; j<=L; j++) { 
             for (int k=1; k<=R; k++) { 
                 d[i][j][k] = d[i-1][j-1][k] + d[i-1][j][k-1] + d[i-1][j][k] * (i-2); 
                 d[i][j][k] %= mod; 
             } 
         } 
     } 
	 printf("%lld\n",d[N][L][R]);

     return 0; 
} 
