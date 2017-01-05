#include <cstdio>
#include <vector>
using namespace std;
vector<int> in,post,pre,inidx,poidx;
void getpre(int ins, int ine, int pos, int poe) {
    //printf("%d %d %d %d\n",ins,ine,pos,poe);
    pre.push_back(post[poe]);
    if(ins==ine) return;
    else if(ine-ins==1) {
        pre.push_back(post[pos]);
        return;
    }
    int lins,line,rins,rine,lpos,lpoe,rpos,rpoe,m;
    m=inidx[post[poe]];
    lins=ins; line=m-1; rins=m+1; rine=ine;
    lpos=pos; lpoe=pos+(line-lins); rpos=lpoe+1; rpoe=poe-1;
    //printf("%d %d %d %d, %d %d %d %d, m:%d\n",lins,line,rins,rine,lpos,lpoe,rpos,rpoe,m);
    if(lins<=line) getpre(lins,line,lpos,lpoe);
    if(rins<=rine) getpre(rins,rine,rpos,rpoe);
}
int main() {
    int n; scanf("%d", &n);
    in.clear(); in.resize(n);
    post.clear(); post.resize(n);
    inidx.clear(); inidx.resize(n+1);
    poidx.clear(); poidx.resize(n+1);
    for(int i=0; i<n; i++) {
        scanf("%d", &in[i]);
        inidx[in[i]]=i;
    }
    for(int i=0; i<n; i++) {
        scanf("%d", &post[i]);
        poidx[post[i]]=i;
    }
    getpre(0,n-1,0,n-1);
    for(int p: pre) printf("%d ", p);
    return 0;
}
