#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;
char str[4];
vector<int> p, size, enemy;
bool first=true;
int find(int a) {
    if(p[a] == a) return a;
    else return p[a]=find(p[a]);
}
int uni(int a, int b) {
    if(a==-1||b==-1) return max(a,b);
    a=find(a); b=find(b);
    if(a==b) return a;
    else {
        size[a] += size[b];
        return p[b]=a;
    }
}
bool dis(int a, int b) {
    a=find(a); b=find(b);
    if(a==b) return false;

    int u=uni(a, enemy[b]), v=uni(enemy[a], b);
    enemy[u]=v; enemy[v]=u;
    return true;
}
bool ack(int a, int b) {
    a=find(a); b=find(b);
    if(a==enemy[b] || b==enemy[a]) return false;

    int u=uni(a,b), v=uni(enemy[a],enemy[b]);
    enemy[u]=v;
    if(v!=-1) enemy[v]=u;
    return true;
}
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n,m,a,b;
        scanf("%d%d",&n,&m);
        p.clear(); size.clear(), enemy.clear();
        p.resize(n); size.resize(n,1); enemy.resize(n,-1);
        for(int i=0; i<n; i++) p[i]=i;
        bool hasAns = true;
        for(int i=1; i<=m; i++) {
            scanf("%s%d%d",str,&a,&b);
            if(!hasAns) continue;
            if(str[0] =='A') {
                if(!ack(a,b)) {
                    printf("CONTRADICTION AT %d\n", i);
                    hasAns=false;
                }
            } else {
                if(!dis(a,b)) {
                    printf("CONTRADICTION AT %d\n", i);
                    hasAns=false;
                }
            }
        }
        if(!hasAns) continue;

        int eIdx, sz=0;
        for(int i=0; i<n; i++) {
            if(p[i] == i) {
                eIdx = enemy[i];
                if(eIdx > i) continue;

                if(eIdx == -1) sz += size[i];
                else sz += max(size[i], size[eIdx]);
            }
        }
        printf("MAX PARTY SIZE IS %d\n", sz);
    }
    return 0;
}
