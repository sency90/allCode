#include <cstdio>
#include "Vector.h"
using namespace std;
#define N 10
int cnt[N+1], idx[N+1], ansIdx[N+1];
struct Info{
    int x,y;
    Info(){} Info(int x, int y):x(x),y(y){}
    bool operator<(const Info& rhs) const {
        if(x==rhs.x) return y<rhs.y;
        else return x<rhs.x;
    }
    void print() {
        printf("(%d,%d) ", x,y);
    }
};
Vector<Info> v;
int main() {
    freopen("input.txt","r",stdin);
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x,y; scanf("%d%d", &x,&y);
        v.push_back(Info(x,y));
    }
    printf("List: ");
    for(int i=0; i<v.size(); i++) v[i].print();
    puts("");

    for(int i=0; i<n; i++) cnt[v[i].y]++;
    for(int i=1; i<=N; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--) idx[--cnt[v[i].y]] = i;

    for(int i=0; i<n; i++) printf("%d ", idx[i]);
    puts("");

    for(int i=0; i<=N; i++) cnt[i] = 0; //init

    for(int i=0; i<n; i++) cnt[v[i].x]++;
    for(int i=1; i<=N; i++) cnt[i]+=cnt[i-1];
    for(int i=n-1; i>=0; i--) ansIdx[--cnt[v[idx[i]].x]] = idx[i];

    for(int i=0; i<n; i++) printf("%d ", ansIdx[i]);
    puts("");


    for(int i=0; i<n; i++) v[ansIdx[i]].print();


    return 0;
}
