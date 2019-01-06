#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
map<int,int> s[100001];
map<int,int> tmp;
int gcd(int b, int l) { return (l==0)?b:gcd(l,b%l); }
int main() {
    int n,q; scanf("%d%d",&n,&q);
    for(int i=0; i<q; i++) {
        int t,x,y,z,v;
        scanf("%d", &t);
        if(t==1 || t==4) {
            scanf("%d%d",&x,&v);
            if(t==1) s[x][v]^=1;
            else printf("%d", s[x][v]);
        } else {
            scanf("%d%d%d",&x,&y,&z);
            if(t==2) {
                if(x==y) {
                    for(auto &it: s[z]) s[x][it.first]^=it.second;
                } else if(x==z){
                    for(auto &it: s[y]) s[x][it.first]^=it.second;
                } else {
                    s[x].clear();
                    for(auto &it: s[y]) s[x][it.first]^=it.second;
                    for(auto &it: s[z]) s[x][it.first]^=it.second;
                }
            } else {
                if(x==y || x==z) {
                    tmp.clear();
                    for(auto &it: s[y]) {
                        for(auto &jt: s[z]) {
                            tmp[gcd(it.first,jt.first)]^=it.second^jt.second;
                        }
                    }
                    s[x] = tmp;
                }
                else {
                    for(auto &it: s[y]) {
                        for(auto &jt: s[z]) {
                            s[x][gcd(it.first,jt.first)]^=it.second^jt.second;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
