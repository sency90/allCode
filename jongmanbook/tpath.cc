#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 0x3f3f3f3f;
int p[2000];
void init(int n) { for(int i=0; i<n; i++) p[i]=i; }
int find(int x) {
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
bool uni(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    if(x>y) swap(x,y);
    p[y]=x;
    return true;
}
int main() {
    int tc;
    scanf("%d", &tc);
    while(tc--) {
        int n,m,s,e,w;
        scanf("%d%d",&n,&m);
        init(n);
        vector<pair<int, pair<int,int> > > ed;
        for(int i=0; i<m; i++) {
            scanf("%d%d%d",&s,&e,&w);
            if(s>e) swap(s,e);
            ed.push_back(make_pair(w,make_pair(s,e)));
        }
        sort(ed.begin(), ed.end());
        int mn,mx=0,ans=inf;
        for(int i=0; i<n; i++) {
            init(n);
            mn = ed[i].first;
            mx = 0;
            for(int j=i; j<ed.size(); j++) {
                s=ed[j].second.first; e=ed[j].second.second;
                if(uni(s,e)) mx=ed[j].first;
                if(find(n-1)==0) {
                    if(ans > mx-mn) ans=mx-mn;
                    break;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
