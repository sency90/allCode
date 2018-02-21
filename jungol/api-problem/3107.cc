/**************************************************************
    Problem: 3107
    User: sency90
    Language: C++
    Result: Success
    Time:32 ms
    Memory:3632 kb
****************************************************************/


#define LEFT 0
#define RIGHT 1
struct Queue{
    int v[300001];
    int f,r;
    Queue():f(0),r(0){}
    inline void push(int x) { v[f++]=x; }
    inline void pop() { r++; }
    inline int front() { return v[r]; }
    inline bool empty() { return f==r; }
    inline int size() { return f-r; }
    inline void init() { f=r=0; }
}q;
int fen[100002],N,ptr,dir;
bool has[100002];
inline void update(int at,int by) {
    for(;at<=N+1; at+=at&-at) fen[at]+=by;
}
inline int query(int at) {
    int ret=0; for(;at;at-=at&-at) ret+=fen[at]; return ret;
}
inline int del(int x) {
    ptr=x;
    has[ptr]=false;
    update(ptr,-1);
    return ptr;
}
inline int findleft(int x) {
    int lo=1,hi=x-1;
    int base = query(x);
    while(lo<=hi) {
        int mid = (lo+hi)>>1;
        int res = query(mid);
        if(res < base) lo=mid+1;
        else hi=mid-1;
    }
    if(has[x]) {
        if(has[lo-1]) return lo-1;
        else return -1;
    } else {
        if(has[lo]) return lo;
        else return -1;
    }
}
inline int findright(int x) {
    int lo=x+1,hi=N;
    int base = (x==0)?0:query(x);
    while(lo<=hi) {
        int mid = (lo+hi)>>1;
        if(base < query(mid)) hi=mid-1;
        else lo=mid+1;
    }
    if(has[x]) {
        if(has[hi]) return hi;
        else return -1;
    } else {
        if(has[hi+1]) return hi+1;
        else return -1;
    }
}

void init(int holder_size,int head) {
    q.init();
    N=holder_size;
    ptr=head+1;
    for(int i=0; i<100002; i++) {
        fen[i]=0;
        has[i]=false;
    }
    dir = LEFT;
}
void insert(int holder) {
    holder++;
    q.push(holder);
    has[holder]=true;
    update(holder,1);
}

int first() {
    while(!q.empty()) {
        int x=q.front(); q.pop();
        if(has[x]) return del(x)-1;
    }
}
int near() {
    if(has[ptr]) return del(ptr)-1;
    int left=findleft(ptr);
    int right=findright(ptr);
    if(left<0) return del(right)-1;
    else if(ptr-left<=right-ptr || right<0) return del(left)-1;
    else return del(right)-1;
}
int forward() {
    if(has[ptr]) return del(ptr)-1;
    if(dir==LEFT) {
        int left = findleft(ptr);
        if(left<0) {
            dir=RIGHT;
            return del(findright(ptr))-1;
        } else return del(left)-1;
    }
    if(dir==RIGHT) {
        int right = findright(ptr);
        if(right<0) {
            dir=LEFT;
            return del(findleft(ptr))-1;
        } else return del(right)-1;
    }
}
int left() {
    if(has[ptr]) return del(ptr)-1;
    int left = findleft(ptr);
    if(left<0) left = findleft(N+1);
    return del(left)-1;
}
int right() {
    if(has[ptr]) return del(ptr)-1;
    int right = findright(ptr);
    if(right<0) right = findright(0);
    return del(right)-1;
}gg
