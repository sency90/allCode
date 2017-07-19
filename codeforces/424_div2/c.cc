#include <iostream>
#include <set>
#include <map>
using namespace std;
map<int,int> chk;
set<int> ans;
int v[2001], g[2001];
int main() {
    int k, n; scanf("%d%d",&k,&n);
    for(int i=0; i<k; i++) scanf("%d", &v[i]);
    for(int i=0; i<n; i++) {
        scanf("%d", &g[i]);
        chk[g[i]]=0;
    }
    for(int i=1; i<=k; i++) {
        int cur=g[0], cnt=0;
        if(chk.count(cur)) {
            if(chk[cur]!=i) {
                cnt++;
                chk[cur]=i;
            }
        }

        for(int j=k-i+1; j<k; j++) {
            cur+=v[j];
            if(chk.count(cur)) {
                if(chk[cur]!=i) {
                    cnt++;
                    chk[cur]=i;
                }
            }
        }

        cur=g[0];
        for(int j=k-i; j>=1; j--) {
            cur-=v[j];
            if(chk.count(cur)) {
                if(chk[cur]!=i) {
                    cnt++;
                    chk[cur]=i;
                }
            }
        }
        cur-=v[0];
        //printf("cnt: %d,  cur: %d,  chk[cur]: %d, i: %d\n", cnt,cur, chk.count(cur)?chk[cur]:-1,i);
        if(cnt==n) {
            if(chk.count(cur) && chk[cur]!=i) continue;
            ans.insert(cur);
        }
    }
    printf("%lu\n", ans.size());
    return 0;
}
