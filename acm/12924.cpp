#include <stdio.h>
#include <vector>
using namespace std;
int ten[10];
bool chk[10000001];
int size(int x) {
    int cnt = 0;
    while(x) {
        x/=10;
        cnt++;
    }
    return cnt;
}
int shiftleft(int x, int sz) {
    int tmp = x%10;
    return tmp*ten[sz]+x/10;
}
void init() {
    ten[0]=1;
    for(int i=1; i<10; i++) {
        ten[i] = ten[i-1]*10;
    }
}
vector<int> v;
int main() {
    init();
    int x, y, cnt=0;
    scanf("%d %d",&x,&y);
    int sz = size(y)-1;
    for(int z=x+1; z<=y; z++) {
        int tmp = z;
        for(int i=0; i<sz; i++) {
            chk[tmp] = true;
            v.push_back(tmp);
            //printf("%d->", tmp);
            tmp=shiftleft(tmp, sz);
            if(chk[tmp]) continue;

            //printf(" %d\n", tmp);
            if(tmp>=x && tmp<=z) cnt++;
        }
        for(int i=0; i<v.size(); i++) {
            chk[v[i]] = false;
        }
        v.clear();
    }
    printf("%d", cnt);
    return 0;
}
