#include <cstdio>
#include <vector>
using namespace std;
void merge(vector<int>& ret, const vector<int>& l, const vector<int>& r, int b) {
    ret.clear();
    ret.push_back(b);
    for(int i=0; i<l.size(); i++) ret.push_back(l[i]);
    for(int i=0; i<r.size(); i++) ret.push_back(r[i]);
}
void split(vector<int>& in, vector<int>& post) {
    if(in.size()<=1) return;

    int idx=0;
    for(int i=0; i<in.size(); i++) {
        if(in[i]==post.back()) {
            idx=i;
            break;
        }
    }
    vector<int> il(in.begin(),in.begin()+idx), ir(in.begin()+idx+1,in.end());
    vector<int> pl(post.begin(),post.begin()+il.size()), pr(post.begin()+il.size(),post.begin()+il.size()+ir.size());
    split(in,il,pl); split(post,ir,pr);
}
void getpre(vector<int>& ret, vector<int>& in, vector<int>& post) {

    getpre(in,il,pl); getpre(post,ir,pr);
    merge(ret,in,post,post.back());
}
int main() {
    int n; scanf("%d", &n);
    vector<int> in(n), post(n);
    for(int i=0; i<n; i++) scanf("%d", &in[i]);
    for(int i=0; i<n; i++) scanf("%d", &post[i]);
    vector<int> ret;
    getpre(ret, in, post);
    for(auto &p: ret) printf("%d ", p);
    return 0;
}
