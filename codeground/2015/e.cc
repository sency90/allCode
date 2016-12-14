#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdlib>
#include <set>
#define xx first
#define yy second
#define r2 (r<<1)
#define m2 ((s+e)>>1)
using namespace std;
typedef pair<int,int> pii;
vector<pii> p,q;
struct Info{
    int p,q,w;
    Info(){} Info(int p, int q, int w):p(p),q(q),w(w){}
    bool operator<(const Info &rhs) const {
        return w>rhs.w;
    }
};
struct Seg{
    int s,e;
    vector<bool> tree;
    Seg(int n):s(0){
        for(e=0; (1<<e)<n; e++);
        tree.resize(1<<(e+1),false);
        e=n-1;
    }
    bool update(int r, int s, int e, int at) {
        if(at<s||e<at) return tree[r];
        else if(s==e) return tree[r]=true;
        else return tree[r]=update(r2,s,m2,at)&update(r2+1,m2+1,e,at);
    }
};
priority_queue<Info> mnh;
int dist(pii &l, pii &r) {
    return max(abs(l.xx-r.xx),abs(l.yy-r.yy));
}
set<int> chk[10002], waitchk[10002];
int n,m;
bool check(int x, int y, Seg &seg) {
    if(x<0||y<0) return false;
    if(chk[x].count(y)) return true;
    if(x==0) {
        if(chk[x].count(y-1)) {
            chk[x].insert(y);
            seg.update(1,seg.s,seg.e,x);
            seg.update(1,seg.s,seg.e,y+m);
            return true;
        } else {
            if(waitchk[x].count(y-1)) {
                if(check(x,y-1,seg)) {
                    waitchk[x].erase(y-1);
                    return true;
                } else return false;
            } else {
                waitchk[x].insert(y);
                return false;
            }
        }
    } else {
        if(chk[x-1].count(y-1)||chk[x].count(y-1)||chk[x-1].count(y)) {
            chk[x].insert(y);
            //if(!chk[x+1].count(y+1) && !chk[x+1].count(y) && !chk[x].count(y+1)) {
            seg.update(1,seg.s,seg.e,x);
            seg.update(1,seg.s,seg.e,y+m);
            return true;
            //}
        } else {
            bool good=false;
            if(waitchk[x-1].count(y-1)) {
                if(check(x-1,y-1,seg)) waitchk[x-1].erase(y-1);
                good=true;
            }
            if(waitchk[x].count(y-1)) {
                if(check(x,y-1,seg)) waitchk[x].erase(y-1);
                good=true;
            }
            if(waitchk[x-1].count(y)) {
                if(check(x-1,y,seg)) waitchk[x-1].erase(y);
                good=true;
            }
            if(!good) {
                waitchk[x].insert(y);
                return false;
            } else return true;
        }
    }
}
int main() {
    int tc;
    setbuf(stdout,NULL);
    scanf("%d",&tc);
    for(int z=1; z<=tc; z++) {
        p.clear(); q.clear();
        scanf("%d%d\n",&m,&n);
        for(int i=0; i<m; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            p.push_back(make_pair(x,y));
        }
        for(int i=0; i<n; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            q.push_back(make_pair(x,y));
        }
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                mnh.push(Info(i,j,dist(p[i],q[j])));
            }
        }
        Seg seg(n+m);
        chk[0].insert(0);
        while(!mnh.empty()) {
            Info in = mnh.top(); mnh.pop();
            //check(in.p,in.q,seg);
            printf("p:%d q:%d dist:%d\n",in.p+1,in.q+1,in.w);

            seg.update(1,seg.s,seg.e,in.p);
            seg.update(1,seg.s,seg.e,in.q+m);
            if(seg.tree[1]) {
                printf("Case #%d\n%d\n",z,in.w);
                break;
            }
        }
        //for(int i=0; i<n+m; i++) printf("tree[%d]: %s\n",i,(seg.tree[i])?"true":"false");
        while(!mnh.empty()) mnh.pop();
    }
    return 0;
}
