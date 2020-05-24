#include <cstdio>
using namespace std;
int fen[20002];
void update(int x) {
    for(; x<=20001; x+=x&-x) fen[x]++;
}
int query(int x) {
    int ret=0;
    for(;x;x-=x&-x) ret+=fen[x];
    return ret;
}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        update(x+10001);
        int lo=1, hi=20001;
        while(lo<=hi) {
            int mid = (lo+hi)/2;
            if(query(mid) >= 1+i/2) hi=mid-1;
            else lo=mid+1;
        }
        printf("%d\n", hi+1-10001);
    }
    return 0;
}
