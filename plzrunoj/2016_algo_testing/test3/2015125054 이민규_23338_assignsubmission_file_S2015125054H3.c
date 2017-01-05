#include <cstdio>
using namespace std;
typedef long long ll;
ll result[101][101][101];
ll mod = 1e9 + 7ll;
ll solve(int n,int left,int right) {
   if(left==1 && right==1) {
      if(n==1) {
         return 1ll;
      } else {
         return 0ll;
      }
   } 
   if(left<1 || right<1 || left+right>n+1){
      return 0ll;
   } 
   if(result[n][left][right]) {
      return result[n][left][right];
   } else {
      return result[n][left][right]=((n-2)*solve(n-1,left,right)+solve(n-1,left-1,right)+solve(n-1,left,right-1))%mod;
   }
}
int main() {
   int n,left,right;
   ll result;
   while(1){
	scanf("%d%d%d",&n,&left,&right);
	if(n>0&&n<101&&left>0&&left<101&&right>0&&right<101){
		break;
	}
   }
   result=solve(n,left,right);
   printf("%lld\n",result);
   return 0;
}