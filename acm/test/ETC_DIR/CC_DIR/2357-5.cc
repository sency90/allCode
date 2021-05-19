#include <stdio.h>
#include <algorithm>
using namespace std;
   
int n,m,minArr[3*100005],maxArr[3*100005],arr[100005];
   
   
int minInit(int s,int e,int index){
    if(s > e)    return 2100000000;
    if(s == e)      return minArr[index] = arr[s];
    return minArr[index] = min(minInit(s, (s+e)/2, index*2), minInit((s+e)/2+1,e, index*2+1));
}
   
int maxInit(int s,int e,int index){
    if(s > e)        return 0;
    if(s == e)      return maxArr[index] = arr[s];
    return maxArr[index] = max(maxInit(s, (s+e)/2, index*2), maxInit((s+e)/2+1,e, index*2+1));
}
   
   
int minFind(int s,int e,int pa,int pb,int index){
       
    if(s > pb || e < pa)        return 2100000000;
    if(pa <= s && pb >= e)        return minArr[index];
      
    
    return min(minFind(s,(s+e)/2, pa, pb, index*2), minFind((s+e)/2+1, e, pa, pb, index*2+1));
}
   
int maxFind(int s,int e,int l,int r,int index){
      
    if(s > r || e < l)        return -1;
    if(l <= s && r >= e)      return maxArr[index];
       
    return max(maxFind(s,(s+e)/2, l, r, index*2), maxFind((s+e)/2+1, e, l, r, index*2+1));
}
   
int main(){
    scanf("%d %d",&n,&m);
   
    for(int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
    }
       
    minInit(0,n-1,1);
    maxInit(0,n-1,1);
  
    for(int i = 0; i < m; i++){
        int a,b;
        scanf("%d %d",&a,&b);
        a--,b--;
        printf("%d %d\n",minFind(0,n-1,a,b,1),maxFind(0,n-1,a,b,1));
    }
}