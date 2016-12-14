#include <cstdio>
#include <vector>
using namespace std;
int d;
int dp[2001][2001][3];
int f(int sum, int idx, int i, bool isf) {
    if(sum==0) {
        if(idx-i<=2) return 1;
        else return 0;
    }
    else if(sum<0) return 0;
    int &ret = dp[sum][idx][idx-i];
    if(ret!=-1) return ret;
    else ret=0;
    if(idx-i<=2) {
        ret+=f(sum-idx,idx,i,false);
    }
    if(!isf) {
        if(idx+1-i<=2) ret+=f(sum-(idx+1),idx+1,i,false);
        if(idx+2-i<=2) ret+=f(sum-(idx+2),idx+2,i,false);
    }
    return ret;
}
vector<int> init;
int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        memset(dp,-1,sizeof(dp));
        init.clear();
        int n;
        scanf("%d%d", &n,&d);
        int lim = n/2;
        for(int i=1; i<=lim; i++) {
            if(i%d==0) init.push_back(i);
        }
        if(n%d==0) init.push_back(n);

        int ans=0;
        for(int p: init) {
            ans+=f(n,p,p,true);
        }
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}
