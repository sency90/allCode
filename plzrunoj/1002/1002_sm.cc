#include <cstdio>
#include <vector>
using namespace std;
vector<int> pre,in,post,preidx,postidx;
void getin(int pres, int pree, int posts, int poste) {
    if(pres==pree) {
        in.push_back(pre[pres]);
        return;
    } else if(pree-pres==1) {
        in.push_back(pre[pree]);
        in.push_back(pre[pres]);
        return;
    }

    int lpres,lpree,rpres,rpree,lposts,lposte,rposts,rposte,llen;
    llen=postidx[pre[pres+1]]-posts;
    lpres=pres+1; lpree=lpres+llen; rpres=lpree+1; rpree=pree;
    lposts=posts; lposte=posts+llen; rposts=lposte+1; rposte=poste-1;

    if(lpres<=lpree) getin(lpres,lpree,lposts,lposte);
    in.push_back(pre[pres]);
    if(rpres<=rpree) getin(rpres,rpree,rposts,rposte);
}
int main() {
    int n; scanf("%d", &n);
    pre.clear(); pre.resize(n);
    post.clear(); post.resize(n);
    preidx.clear(); preidx.resize(n+1);
    postidx.clear(); postidx.resize(n+1);
    for(int i=0; i<n; i++) {
        scanf("%d", &pre[i]);
        preidx[pre[i]]=i;
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &post[i]);
        postidx[post[i]]=i;
    }
    getin(0,n-1,0,n-1);
    for(int i=0; i<in.size(); i++) {
        printf("%d ", in[i]);
    }
    return 0;
}
