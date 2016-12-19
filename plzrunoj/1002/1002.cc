#include <cstdio>
#include <vector>
#include <ctime>
#include <algorithm>
#include <random>
using namespace std;
#define r2 (r<<1)
vector<int> v,pre,post,in,preidx,postidx;
vector<vector<int> > tree;
int n;
void f(int r) {
    if(r2<=n) {
        tree[r].push_back(r2);
        f(r2);
    }
    if(r2+1<=n) {
        tree[r].push_back(r2+1);
        f(r2+1);
    }
}

int cnt;
FILE *_fin;
void preOrder(int r) {
    fprintf(_fin, "%d ", v[r]);
    //printf("%d ", v[r]);
    pre.push_back(v[r]);
    preidx[v[r]]=cnt++;
    if(tree[r].size()>=1) {
        preOrder(r2);
        if(tree[r].size()==2) preOrder(r2+1);
    }
}
void postOrder(int r) {
    if(tree[r].size()>=1) {
        postOrder(r2);
        if(tree[r].size()==2) postOrder(r2+1);
    }
    fprintf(_fin, "%d ", v[r]);
    //printf("%d ", v[r]);
    post.push_back(v[r]);
    postidx[v[r]]=cnt++;
}
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
char title[10];
int main() {
    n=1000;
    int idx=0;
    while(n>=0) {
        if(n==0) n=1;
        srand(time(0));
        pre.clear(); post.clear(); in.clear();
        preidx.clear(); preidx.resize(n+1);
        postidx.clear(); postidx.resize(n+1);
        tree.clear(); tree.resize(n+1, vector<int>());
        v.clear(); for(int i=0; i<=n; i++) v.push_back(i);
        f(1);

        random_device rd;
        mt19937 g(rd());
        shuffle(v.begin()+1, v.end(), g);

        sprintf(title, "%d.in", ++idx);
        FILE *fin = fopen(title, "w");
        _fin=fin;
        fprintf(fin, "%d\n", n);
        //printf("%d\n", n);
        cnt=0; preOrder(1); fprintf(fin,"\n"); //puts("");
        cnt=0; postOrder(1); fprintf(fin,"\n"); //puts("");
        fclose(fin);

        sprintf(title, "%d.out", idx);
        FILE *fout = fopen(title, "w");
        getin(0,n-1,0,n-1);
        for(int i=0; i<in.size(); i++) {
            fprintf(fout, "%d ", in[i]);
            //printf("%d ", in[i]);
        }

        n-=100;
    }
    return 0;
}


