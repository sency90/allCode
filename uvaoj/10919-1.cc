#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
bool chk[10001];
int main() {
    while(true) {
        memset(chk,false,sizeof(chk));
        int k; scanf("%d", &k);
        if(k==0) return 0;
        int m; scanf("%d", &m);

        for(int i=0; i<k; i++) {
            int x; scanf("%d", &x);
            chk[x]=true;
        }
        bool hasAns=true;
        for(int i=0; i<m; i++) {
            int c,r; scanf("%d%d",&c,&r);
            int cnt=0;
            for(int j=0; j<c; j++) {
                int x; scanf("%d", &x);
                if(chk[x]) cnt++;
            }
            if(cnt<r) hasAns=false;
        }
        if(hasAns) puts("yes");
        else puts("no");
    }
    return 0;
}
