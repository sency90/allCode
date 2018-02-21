extern int add_lot();
extern void assign(int lot_num,int s,int size,int member_id);
extern void back(int lot_num,int s,int size);
extern void grow(int lot_num,int s,int size,int crop);

#include <queue>
using namespace std;
struct Info{
    int lotno,s,size;
    Info(){} Info(int lotno,int s,int size):lotno(lotno),s(s),size(size){}
    bool operator<(const Info &rhs) const {
        if(lotno == rhs.lotno) return size<rhs.size;
        else return lotno>rhs.lotno;
    }
};
priority_queue<Info> mxh[10001];
int cur_mxlot;
void init_member() {
    for(int i=1; i<=100; i++) {
        mxh[0].push(Info(i,0,100000));
    }
    cur_mxlot=0;
}

void assign_member(int id,int size) {
    while(!mxh[0].empty() && size>0) {
        Info t = mxh[0].top(); mxh[0].pop();
        if(t.lotno > cur_mxlot) {
            cur_mxlot=t.lotno;
            add_lot();
        }
        if(size <= t.size) {
            mxh[id].push(Info(t.lotno,t.s,size));
            assign(t.lotno,t.s,size,id);
            if(size < t.size) mxh[0].push(Info(t.lotno,t.s+size,t.size-size));
            return;
        } else {
            mxh[id].push(t);
            size-=t.size;
            assign(t.lotno,t.s,t.size,id);
        }
    }
}

void back_member(int id) {
    while(!mxh[id].empty()) {
        Info t = mxh[id].top(); mxh[id].pop();
        mxh[0].push(t);
        back(t.lotno,t.s,t.size);
    }
}

Info tmp[10001];
void grow_member(int id,int crop) {
    int cnt=0;
    while(!mxh[id].empty()) {
        tmp[cnt++] = mxh[id].top(); mxh[id].pop();
    }
    for(int i=0; i<cnt; i++) {
        grow(tmp[i].lotno,tmp[i].s,tmp[i].size,crop);
        mxh[id].push(tmp[i]);
    }
}
