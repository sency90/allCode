#include <cstdio>
#include <cstring>
#include <stack>
#include <algorithm>
using namespace std;
char v[51][51], g[51][51];
int discov[51], bcc[51];
int n,d,dscnt=0,no=0;
stack<int> s;
int dfs(int x, int p) {
    s.push(x);
    int ret=discov[x]=++dscnt;
    for(int i=0; i<n; i++) {
        if(v[x][i]=='Y') {
            if(!discov[i]) ret = min(ret,dfs(i,x));
            else if(i!=p&&!bcc[i]) ret = min(ret,discov[i]);
        }
    }
    if(ret==discov[x]) {
        //printf("ret:%d, discov[%d]:%d\n",ret,x,discov[x]);
        no++;
        while(true) {
            int z = s.top(); s.pop();
            //printf("z: %d\n",z);
            bcc[z]=no;
            if(discov[z]==discov[x]) break;
        }
    }
    return ret;
}
bool chk[51];
int start,mx;
void dfs2(int x, int len) {
    if(mx<len) {
        mx=len;
        start=x;
    }
    chk[x]=true;
    for(int i=1; i<=no; i++) {
        if(g[x][i]&&!chk[i]) {
            dfs2(i,len+1);
        }
    }
}
int main() {
    bool hasAns=false;
    scanf("%d%d", &n,&d);
    for(int i=0; i<n; i++) {
        scanf("%s",v[i]);
        int lim = strlen(v[i]);
        for(int j=0; j<lim; j++) {
            if(v[i][j]=='Y') hasAns=true;
        }
    }
    if(n==1) return 0&puts("0");
    else if(!hasAns) return 0&puts("-1");

    bool light=false;
    for(int i=0; i<n; i++) {
        if(!discov[i]&&!light) {
            dfs(i,-1);
            light=true;
        } else if(!discov[i]&&light) {
            return 0&puts("-1");
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(v[i][j]=='Y') {
                if(bcc[i]!=bcc[j]) g[bcc[i]][bcc[j]]=true;
            }
        }
    }
    dfs2(1,0);
    memset(chk,false,sizeof(chk));
    dfs2(start,0);
    printf("%d", mx*d);
    return 0;
}
