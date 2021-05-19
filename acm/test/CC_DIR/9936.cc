#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int ninf = 0xc0c0c0c0;
int v[1002][3], d[1001][1001][11];
int cnt[]={0,1,1,1,1,1,2,2,2,2,2};
int state[]={0x00,0x11,0x22,0x44,0x03,0x06,0x33,0x55,0x66,0x17,0x47};
vector<vector<int> > prv(11, vector<int>());
int n,k;
void init() {
    for(int i=0; i<=10; i++) {
        for(int j=0; j<=10; j++) {
            if(!((state[i]&0x0f)&(state[j]>>4))) prv[j].push_back(i);
        }
    }
}
int value(int x, int s) {
    int ret = 0, st=state[s];
    if(st && x<0) return ninf;
    for(int i=0; i<3; i++, st>>=1) ret += (st&1)*v[x][i];
    st>>=1;
    if(st && x-1<0) return ninf;
    for(int i=0; i<3; i++, st>>=1) ret += (st&1)*v[x-1][i];

    return ret;
}
int f(int x, int c, int s) {
    if(x<0) {
        if(c==0) return 0;
        else return ninf;
    } else if(c==0) return 0;

    int &ret = d[x][c][s];
    if(ret!=ninf) return ret;

    for(auto &ps : prv[s]) {
        if(c>=cnt[ps]) ret = max(ret, f(x-1,c-cnt[ps],ps)+value(x-1,ps));
    }
    return ret;
}
int main() {
    scanf("%d%d",&n,&k);
    init();
    memset(d, 0xc0, sizeof(d));
    for(int i=0; i<n; i++) {
        for(int j=2; j>=0; j--) {
            scanf("%d", &v[i][j]);
        }
    }
    printf("%d\n", f(n,k,0));
    return 0;
}
