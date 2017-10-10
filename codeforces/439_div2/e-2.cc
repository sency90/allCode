#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <ctime>
#include <cstring>
#include <cstdio>
using namespace std;
#define r4 (r<<2)
//#define mx2 ((sx+ex)>>1)
//#define my2 ((sy+ey)>>1)
typedef pair<int,int> pii;
typedef pair<pii,pii> piipii;
typedef long long ll;
map<piipii,int> mp;
int n,m,q;
int sx=1,sy=1,ex,ey,sz=1;
vector<ll> lazy,tree;

#include <cstdio>
#include <cctype>
#include <algorithm>
using namespace std;
class FastIO{
    int fd,bufsz;
    char *buf,*cur,*end;
    public:
    FastIO(int fd=0, int bufsz=(1<<25)):fd(fd),bufsz(bufsz) {
        buf=cur=end=new char[bufsz];
    }
    ~FastIO() { delete[] buf; }
    bool readbuf() {
        cur=buf;
        end=buf+bufsz;
        while(true) {
            size_t res=fread(cur,sizeof(char),end-cur,stdin);
            if(res==0) break;
            cur+=res;
        }
        end=cur;
        cur=buf;
        return buf!=end;
    }
    int readint() {
        while(true) {
            if(cur==end) readbuf();
            if(isdigit(*cur)||*cur=='-') break;
            ++cur;
        }
        bool sign=true;
        if (*cur=='-') {
            sign=false;
            ++cur;
        }
        int ret=0;
        while(true) {
            if(cur==end && !readbuf()) break;
            if(!isdigit(*cur)) break;
            ret=ret*10+(*cur-'0');
            ++cur;
        }
        return sign?ret:-ret;
    }
};

inline void pushdown(int r, int sx, int sy, int ex, int ey) {
    //if(lazy[r]) {
        if(!(sx==ex && sy==ey)) {
            int a,b,c,d;
            if(r&1) a=r4+1,b=r4+2,c=r4+5,d=r4+6;
            else a=r4-1,b=r4,c=r4+3,d=r4+4;
            lazy[a] += lazy[r];
            lazy[b] += lazy[r];
            lazy[c] += lazy[r];
            lazy[d] += lazy[r];
        } else tree[r] += lazy[r]; //단말노드에만 tree[r]값 갱신해준다.
        //tree[r]+=lazy[r]*(ex-sx+1)*(ey-sy+1); //근데 단말 노드가 아니면 이 정보가 필요가 없음.
        lazy[r]=0;
    //}
}
void update(int r, int sx, int sy, int ex, int ey, int qsx, int qsy, int qex, int qey, int by) {
    if(lazy[r]) pushdown(r,sx,sy,ex,ey);
    if(ex<qsx || qex<sx || ey<qsy || qey<sy) return; //tree[r];
    else if(qsx<=sx && ex<=qex && qsy<=sy && ey<=qey) {
        lazy[r]+=(ll)by;
        if(lazy[r]) pushdown(r,sx,sy,ex,ey);
        //return tree[r];
    } else {
        int mx2=(sx+ex)>>1, my2=(sy+ey)>>1, t=r4;
        int a,b,c,d;
        if(r&1) a=r4+1,b=r4+2,c=r4+5,d=r4+6;
        else a=r4-1,b=r4,c=r4+3,d=r4+4;

        update(a, sx,sy, mx2,my2, qsx,qsy,qex,qey,by);
        update(b, sx,my2+1, mx2,ey, qsx,qsy,qex,qey,by);
        update(c, mx2+1,sy, ex,my2, qsx,qsy,qex,qey,by);
        update(d, mx2+1,my2+1, ex,ey, qsx,qsy,qex,qey,by);
    }
}
ll query(int r, int sx, int sy, int ex, int ey, int qx, int qy) {
    if(lazy[r]) pushdown(r,sx,sy,ex,ey);
    if(ex<qx || qx<sx || ey<qy || qy<sy) return 0; //tree[r];
    else if(sx==ex && sy==ey) return tree[r];
    else {
        int mx2=(sx+ex)>>1, my2=(sy+ey)>>1;
        int a,b,c,d;
        if(r&1) a=r4+1,b=r4+2,c=r4+5,d=r4+6;
        else a=r4-1,b=r4,c=r4+3,d=r4+4;

        ll u=query(a,sx,sy,mx2,my2,qx,qy);
        ll v=query(b,sx,my2+1,mx2,ey,qx,qy);
        ll w=query(c,mx2+1,sy,ex,my2,qx,qy);
        ll z=query(d,mx2+1,my2+1,ex,ey,qx,qy);
        return u+v+w+z;
    }
}
int main() {
    FastIO fio;
    n=fio.readint();
    m=fio.readint();
    q=fio.readint();
    //scanf("%d%d%d",&n,&m,&q);
    int i;
    sx=sy=ex=ey=sz=i=1;
    for(;i<max(n,m);i<<=1) sz+=i*i;
    sz+=i*i, ex=n, ey=m;

    //tree.clear(); tree.resize(sz);
    //lazy.clear(); lazy.resize(sz);
    tree.resize(sz); lazy.resize(sz);
    for(int i=0; i<q; i++) {
        int t=fio.readint(),x1=fio.readint(),y1=fio.readint(),x2=fio.readint(),y2=fio.readint();
        //scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
        if((x1==x2 && y1>y2) || x1>x2) swap(x1,x2),swap(y1,y2);
        if(t==1) {
            int val = (rand()<<15)|rand();
            mp[piipii(pii(x1,y1),pii(x2,y2))]=val;
            update(0,sx,sy,ex,ey,x1,y1,x2,y2,val);
        } else if(t==2) {
            int val = mp[piipii(pii(x1,y1),pii(x2,y2))];
            update(0,sx,sy,ex,ey,x1,y1,x2,y2,-val);
        } else {
            if(query(0,sx,sy,ex,ey,x1,y1) == query(0,sx,sy,ex,ey,x2,y2)) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
