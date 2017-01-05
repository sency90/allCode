#include <cstring>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
set<int> s[2];
int main() {
    int n,c,d,pos=0;
    scanf("%d", &n);
    bool ans=true,zero=false,one=false;
    for(int i=0; i<n; i++) {
        scanf("%d%d",&c,&d);
        if(d==2) d=0;
        s[d].insert(pos);
        auto jt=s[0].end(), kt=s[1].begin();
        if(jt!=s[0].begin()) {
            jt--;
            if(kt!=s[1].end()) {
                if(*jt>*kt) ans=false;
            }
        }

        auto it = s[d^1].lower_bound(pos);
        if(d==0 && it!=s[d^1].begin()) ans=false;
        if(d==1 && it!=s[d^1].end()) ans=false;
        pos+=c;
        if(d==0) zero=true;
        else one=true;
    }

    if(one&&!zero) printf("Infinity");
    else if(zero) {
        if(!ans) return 0&printf("Impossible");
        else {
            auto it = s[0].end();
            it--;
            printf("%d", pos-(*it)+1899);
        }
    } else printf("Impossible");
    return 0;
}
