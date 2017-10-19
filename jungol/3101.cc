#include <stdio.h>
struct Queue{
    int v[1000001];
    int f,r;
    Queue():f(0),r(0){}
    inline void push(int x) { v[f++]=x; }
    inline void pop() { r++; }
    inline bool empty() { return f<=r; }
    inline int size() { return f-r; }
    inline int front() { return v[r]; }
    void init() {
        for(int i=f,j=f-r; i>=r && j>=0; i--,j--) v[j]=v[i];
        f-=r;
        r=0;
    }
};
Queue q;
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1; i<=n; i++) q.push(i);
    int cnt=0;
    while(!q.empty()) {
        for(int i=0; i<k-1; i++) q.push(q.front()),q.pop();
        printf("%d ",q.front()); q.pop();
        if(cnt++>=90) q.init(),cnt=0;
    }
    return 0;
}
