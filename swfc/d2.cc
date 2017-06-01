#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
int r[101], already[101], s[101], sp[101], b[101], bp[101];
const int inf = 0x3f3f3f3f;
bool judge(int x, int m) {
    for(int i=0; i<n; i++) {
        int cnt = r[i]*x-already[i];
        int limp=(cnt+s[i]-1)/s[i];
        int mn=inf;
        for(int p=0; p<=limp; p++) {
            int q=(cnt-p*s[i]+b[i]-1)/b[i];
            mn=min(mn,p*sp[i]+q*bp[i]);
        }
        m-=mn;
        if(m<0) return false;
    }
    return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%d%d%d%d%d%d",&r[i],&already[i],&s[i],&sp[i],&b[i],&bp[i]);
    }
    int lo=0, hi=100000;
    while(lo<=hi) {
        int mid = (lo+hi)>>1;
        if(judge(mid,m)) lo=mid+1;
        else hi=mid-1;
    }
    printf("%d", lo-1);
    return 0;
}
