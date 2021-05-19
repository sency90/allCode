#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pii;
int paren[100001];
bool dock[100001];
vector<pii> v;
inline void init(int n) {
    for(int i=0; i<=n; i++) {
        paren[i] = i;
    }
}
inline int find(int x) {
    if(x==paren[x]) return x;
    else return paren[x] = find(paren[x]);
}
inline int uni(int x, int y) {
    if(x<=0 || y<=0) return 0;
    x=find(x); y=find(y);
    if(x>y) swap(x,y);
    return paren[y] = x;
}

int main() {
    int g,p; scanf("%d%d",&g,&p);
    init(g);
    int cnt=0;
    bool good = true;
    for(int i=0; i<p; i++) {
        int x; scanf("%d", &x);
        if(!good) continue;
        x = find(x);
        if(x>0 && !dock[x]) {
            dock[x] = true;
            cnt++;
        }
        else {
            int idx = uni(x-1,x);
            while(dock[idx]) {
                idx = uni(find(find(idx)-1), idx);
            }
            if(idx<=0) {
                good = false;
                continue;
            }
            dock[idx] = true;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
