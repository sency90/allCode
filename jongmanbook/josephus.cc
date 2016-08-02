#include <stdio.h>
#include <algorithm>
#include <deque>
using namespace std;
deque<int> dq;
int main() {
    int t,n,k;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d",&n,&k);
        for(int i=1; i<=n; i++) {
            dq.push_back(i);
        }
        if(n==3) {
            dq.pop_front();
        } else {
            for(int i=0; i<n-2; i++) {
                dq.pop_front();
                for(int j=1; j<k; j++) {
                    dq.push_back(dq.front());
                    dq.pop_front();
                }
            }
        }
        int a = dq.front(); dq.pop_front();
        int b = dq.front(); dq.pop_front();
        if(a>b) swap(a,b);
        printf("%d %d\n", a, b);
    }
    return 0;
}
