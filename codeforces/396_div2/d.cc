#include <cstdio>
#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
int p[100002], enemy[100002];
map<string, int> mp;
void init(int n) {
    for(int i=0; i<=n; i++) p[i]=i;
    memset(enemy,-1,sizeof(enemy));
}
int find(int x) {
    if(p[x]==x) return x;
    else return p[x]=find(p[x]);
}
int uni(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    else {
        if(x>y) swap(x,y);
        p[y]=x;
        return true;
    }
}
bool rel(int x, int y) {
    x=find(x); y=find(y);
    if(x==y || enemy[y]==x) return true;
    else return false;
}
bool hate(int x, int y) {
    x=find(x); y=find(y);
    return (enemy[y]==x);
}
bool dis(int x, int y) {
    x=find(x); y=find(y);
    if(x==y) return false;
    if(enemy[y]!=-1) uni(x,enemy[y]);
    if(enemy[x]!=-1) uni(y,enemy[x]);
    x=find(x); y=find(y);
    enemy[x]=y;
    enemy[y]=x;

    return true;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,q;
    cin >> n>>m>>q;
    init(n+1);
    string s,x,y;
    int cnt=0;
    for(int i=0; i<n; i++) {
        cin >> s;
        mp[s]=cnt++;
    }
    int a;
    for(int i=0; i<m; i++) {
        cin >>a >>x>>y;
        int u=mp[x], v=mp[y];
        if(rel(u,v)) {
            u=find(u); v=find(v);
            if(u==v && a==1) puts("YES");
            else if(enemy[u]==v && a==2) puts("YES");
            else puts("NO");
        } else {
            if(a==2) {
                if(!dis(u,v)) puts("NO");
                else puts("YES");
            } else if(a==1) {
                puts("YES");
                uni(u,v);
            }
        }
    }
    for(int i=0; i<q; i++) {
        cin >> x>>y;
        int u=mp[x], v=mp[y];
        if(!rel(u,v)) puts("3");
        else {
            u=find(u); v=find(v);
            if(u==v) puts("1");
            else puts("2");
        }
    }
    return 0;
}
