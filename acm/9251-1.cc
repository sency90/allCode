#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
string a,b;
vector<int> pos[26];
inline int chg(char c) {
    return c-'A';
}

struct Seg{
    int s,e;
    vector<int> tree;
    Seg(int n):s(1) {
        for(e=0; (1<<e)<n; e++);
        tree.clear(); tree.resize((1<<(e+1)), 0);
        e=1<<e;
    }
    int update(int r, int s, int e, int idx, int x) {
        if(idx<s||e<idx) return tree[r];
        if(s==e) return tree[r]=x;
        int mid = (s+e)>>1;
        return tree[r] = max(update(r<<1,s,mid,idx,x),update((r<<1)+1,mid+1,e,idx,x));
    }
    int query(int r, int s, int e, int qs, int qe) {
        if(qe<s||e<qs) return 0LL;
        if(qs<=s&&e<=qe) return tree[r];
        int mid=(s+e)>>1;
        return max(query(r<<1,s,mid,qs,qe),query((r<<1)+1,mid+1,e,qs,qe));
    }
};

Seg *seg;
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> a >> b;

    for(int i=0; i<b.size(); i++) {
        pos[chg(b[i])].push_back(i);
    }

	seg = new Seg(b.size());
    for(int i=0; i<a.size(); i++) {
        if(pos[chg(a[i])].empty()) continue;
        for(int j=pos[chg(a[i])].size()-1; j>=0; j--) {
            int mx = seg->query(1,seg->s,seg->e,1,pos[chg(a[i])][j]);
            seg->update(1,seg->s,seg->e,pos[chg(a[i])][j]+1, mx+1);
        }
    }

    printf("%d", seg->query(1,seg->s,seg->e,1,b.size()));
	delete seg;
    return 0;
}
