#include <cstdio>
#include <vector>
using namespace std;
vector<int> in, post, ret;
void merge()
//in-order => [is,ie)
//post-order => [ps,pe)
void getpre(int is, int ie, int ps, int pe) {
    int idx=0;
    for(int i=is; i<ie; i++) {
        if(in[i]==post[pe-1]) {
            idx=i;
            break;
        }
    }
    if(is==idx || ie==idx+1) {
        for(int i=is; i<ie; i++) ret.push_back(in[i]);
        return;
    }

    vector<int> ret;
    ret.push_back(post[pe-1]);
    merge(getpre(is,idx+1),getpre(idx+1,ie));
}
int main() {
    int n;
    scanf("%d", &n);
    in.resize(n); post.resize(n); ret.resize(n);
    for(int i=0; i<n; i++) scanf("%d", &in[i]);
    for(int i=0; i<n; i++) scanf("%d", &post[i]);
    getpre(0,post.size());
    for(auto &p: ret) printf("%d ", p);
    return 0;
}
