#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
struct Value{
    int val, x;
    Value() {}
    Value(int vall, int xx) {val=vall; x=xx;}
    bool operator<(const Value& rhs) const {
        return val > rhs.val;
    }
};
struct Point{
    //int val, x, cnt;
    int x, cnt;
    Point() {}
    Point(int xx, int cntt) { x=xx; cnt=cntt; }
    Point operator+(const Point& rhs) const {
        return Point(x+rhs.x, cnt+rhs.cnt);
    }
    void print() {
        printf("x:%d cnt:%d", x, cnt);
    }
};
int cnt[50001];
vector<Value> co;
vector<Point> d(150000);
Point init(int x, int s, int e) {
    if(s==e) {
        if(cnt[s]) return d[x] = Point(s, cnt[s]);
        else return d[x] = Point(0,0);
    } else return d[x] = init(2*x, s, (s+e)/2) + init(2*x+1, (s+e)/2+1, e);
}
Point query(int x, int s, int e, int i, int j) {
    if(j<s || e<i) return Point(0,0);
    else if(i<=s && e<=j) return d[x];
    else return query(2*x, s, (s+e)/2, i, j)+query(2*x+1, (s+e)/2+1, e, i, j);
}
int main() {
    int n, v, x;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&v,&x);
        co.push_back(Value(v,x));
        cnt[x]++;
    }
    sort(co.begin(), co.end());

    long long sum=0LL, tmp;
    init(1,0,n);
    for(int i=0; i<co.size(); i++) {
        Point l = query(1,0,n,0,co[i].x);
        Point r = query(1,0,n,co[i].x,n);
        printf("(v:%d, x:%d)=> ",co[i].val, co[i].x);
        l.print(); printf(" | "); r.print(); puts("");
        tmp = (l.cnt*co[i].x-l.x)*co[i].val + (r.x-r.cnt*co[i].x)*co[i].val;
        printf("tmp: %lld\n", tmp);
        sum += tmp;
        //sum += ( (l.cnt-r.cnt)*co[i].x + (r.x-l.x) )*co[i].val;
    }
    printf("%lld", sum);
    return 0;
}
