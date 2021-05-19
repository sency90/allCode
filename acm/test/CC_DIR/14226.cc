#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
#define x first
#define y second.first
#define z second.second
typedef pair<int,int> pii;
typedef pair<int,pii> pipii;
priority_queue<pipii,vector<pipii>,greater<pipii>> mnh;
bool chk[3001][3001];
int main() {
    int n; scanf("%d", &n);
    mnh.push({0,{0,1}});
    while(!mnh.empty()) {
        pipii a = mnh.top(); mnh.pop();
        if(a.y>3000||a.z>3000) continue;
        if(chk[a.y][a.z]) continue;
        chk[a.y][a.z]=true;
        if(a.z==n) return 0&printf("%d\n", a.x);
        mnh.push({a.x+1,{a.y,a.z+a.y}});
        mnh.push({a.x+1,{a.z,a.z}});
        if(a.z!=1) mnh.push({a.x+1,{a.y,a.z-1}});
    }
    return 0;
}
