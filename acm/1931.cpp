#include <stdio.h>
#include <algorithm>
using namespace std;
struct Time{
    int s, e;
    bool operator<(const Time& rhs) const {
        if(e == rhs.e) {
            return s < rhs.s;
        } else return e < rhs.e;
    }
}t[100000];
int main() {
    int n, i, j, cnt;
    scanf("%d", &n);
    for(i=0; i<n; i++) {
        scanf("%d %d", &t[i].s, &t[i].e);
    }
    if(n==1) {
        puts("1");
        return 0;
    }
    sort(t, t+n);
    for(i=0, cnt=1; i<n-1;) {
        for(j=i+1; j<n; j++) {
            if(t[i].e <= t[j].s) {
                cnt++;
                i=j;
                break;
            }
        } if(j==n) break;
    } printf("%d", cnt);
    return 0;
}
