#include <iostream>
#include <algorithm>
using namespace std;
int n,m,x;
int c[100001], s[100001];
bool judge(int cnt) {
    int sum=0;
    for(int i=0; i<cnt; i++) {
        if(c[i]>s[m-cnt+i]) {
            sum+=c[i]-s[m-cnt+i];
            if(sum>x) return false;
        }
    }
    return true;
}
int main() {
    scanf("%d%d%d",&n,&m,&x);
    for(int i=0; i<n; i++) scanf("%d", &c[i]);
    for(int i=0; i<m; i++) scanf("%d", &s[i]);
    sort(c,c+n); sort(s,s+m);
    int lo=0,hi=min(n,m);
    while(lo <= hi) {
        int mid = (lo+hi)>>1;
        if(judge(mid)) lo=mid+1;
        else hi=mid-1;
    }
    printf("%d", lo-1);
    return 0;
}

