#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int,int> pii;
char s[100001][2];
int v[100001];
int basis[4];
bool chk[100001][4];
void init() {
    basis[0]=0; basis[1]=1;
    for(int i=0; i<10; i+=2) {
        basis[2]|=(1<<i);
    }
    for(int i=1; i<10; i+=2) {
        basis[3]|=(1<<i);
    }
}
vector<pii> ans[4];
int main() {
    int n,k; scanf("%d",&n);
    init();
    int t[4];
    for(int i=0; i<4; i++) t[i]=basis[i];
    for(int i=1; i<=n; i++) {
        scanf("%s%d",s[i],&v[i]);

        int cnt=0,memj;
        for(int j=0; j<4; j++) {
            if(s[i][0]=='|') t[j]|=v[i];
            else if(s[i][0]=='&') t[j]&=v[i];
            else t[j]^=v[i];

            if(!chk[t[j]][j]) cnt++;
            else memj=j;
            chk[t[j]][j]=true;
        }
        bool eraseAll=true;
        for(int j=0; j<4; j++) {
            if(t[j]!=basis[j]) {
                eraseAll=false;
                break;
            }
        }
        if(eraseAll) {
            for(int j=0; j<4; j++) ans[j].clear();
            continue;
        }
        if(cnt==4) {
            for(int j=0; j<4; j++) {
                chk[t[j]][j]=true;
                ans[j].push_back(pii(t[j],i));
            }
        } else {
            int idx=0;
            for(int u=0; u<ans[memj].size(); u++) {
                if(ans[memj][u].first == t[memj]) {
                    idx=u;
                    break;
                }
            }
            //auto it = lower_bound(ans[memj].begin(), ans[memj].end(), pii(t[memj],0));
            //int idx = it-ans[memj].begin();
            //printf("idx: %d, memj: %d\n",idx,memj);
            for(int j=0; j<4; j++) {
                ans[j].erase(ans[j].begin()+idx+1,ans[j].end());
            }
        }
    }
    printf("%lu\n", ans[0].size());
    for(int i=0; i<ans[0].size(); i++) {
        int x=ans[0][i].second;
        printf("%c %d\n",s[x][0],v[x]);
    }
    return 0;
}
