#include <stdio.h>
long long v[]={0,1,2,4,10,32,122,544,2770,15872,101042,707584,5405530,44736512,398721962,3807514624,38783024290,419730685952,4809759350882,58177770225664,740742376475050};
int main() {
    int n,tc; scanf("%d", &tc);
    while(tc--) {
        scanf("%d", &n);
        printf("%lld\n", v[n]);
    }
    return 0;
}

/*
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
typedef long long ll;
set<int> chk;
int n;
ll ans, d[22][22][2];
ll dfs(int pos, int prev, int big) {
if(pos==0) {
if(chk.size() == n) return 1LL;
return 0LL;
}
ll &ret = d[pos][prev][big];
if(ret!=-1LL) return ret;
else ret=0LL;

if(big) {
for(int i=prev+1; i<=n; i++) {
if(chk.count(i)) continue;
chk.insert(i);
ret += dfs(pos-1,i,big^1);
chk.erase(i);
}
} else {
for(int i=1; i<prev; i++) {
if(chk.count(i)) continue;
chk.insert(i);
ret += dfs(pos-1,i,big^1);
chk.erase(i);
}
}
return ret;
}
int main() {
freopen("/Users/lian/allCode/acm/3948-2.cc", "w", stdout);
printf("#include <stdio.h>\nlong long v[]={0,1,");
for(int i=2; i<=20; i++) {
n=i;
memset(d,-1,sizeof(d));
if(i==20) printf("%lld};\n", dfs(i,0,1)+dfs(i,i+1,0));
else printf("%lld,", dfs(i,0,1)+dfs(i,i+1,0));
}
puts("int main() {\n int n,tc; scanf(\"\%d\", &tc);\n while(tc--) {\n scanf(\"\%d\", &n);\n printf(\"\%lld\\n\", v[n]);\n }\n return 0;\n}");
return 0;
}
*/
