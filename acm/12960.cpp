#include <stdio.h>
#include <string>
using namespace std;
int info[27],N,M,K;
string str="";
long long f(int n, int x, string str) {
    if(n<x) return 0;
    if(n==N+1) return 0;

    long long ans=0LL;
    for(int i=0; i<x; i++) {
        int s=0, e=n-1, cnt=0;
        string sss = str+(char)('a'+i);
        while(s<e) if(sss[s++] != sss[e--]) cnt+=2;
        if(s==e) cnt++;
        if(cnt==n) { //이 경우가 해당 문자열이 팰린드롬인 경우다.
            ans += info[x];
        }
    }
    return f(n+1, x) + f(n+1, x+1) + ans;
}
int main() {
    info[1]=26;
    for(int i=2; i<=26; i++) {
        info[i]+=info[i-1]-1;
    }
    scanf("%d%d%d",&N,&M,&K);
    long long ans = 1LL;
    if(K==0) {
        for(int i=0; i<N; i++) {
            ans*=26LL;
        }
        if(ans==1LL) puts("0");
        else printf("%lld", ans);
    }
    f(0,0,"");
    return 0;
}
