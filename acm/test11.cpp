#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
struct Info{
    int x, y;
    Info(int xx, int yy) {
        x=xx; y=yy;
    }
    //for sorting
    bool operator<(const Info &rhs) const{
        if(x == rhs.x) return y < rhs.y;
        else return x < rhs.x;
    }
    //for mxh
    bool operator>(const Info &rhs) const{
        if(x == rhs.x) return y > rhs.y;
        else return x > rhs.x;
    }
};
priority_queue<Info, vector<Info>, greater<Info> > mnh; //maxheap
vector<Info> v;
int main() {
    int n, x, y;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d %d", &x, &y);
        v.push_back(Info(x,y));
        mnh.push(Info(x,y));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<n; i++) {
        printf("%d %d\n", v[i].x, v[i].y);
    }
    puts("");
    while(!mnh.empty()) {
        Info tmp = mnh.top(); mnh.pop();
        printf("%d %d\n", tmp.x, tmp.y);
    }
    return 0;
}
