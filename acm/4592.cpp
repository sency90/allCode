#include <stdio.h>
#include <queue>
using namespace std;
queue<int> q;
int main() {
    int n, d, pd;
    while(true) {
        pd=-1;
        scanf("%d", &n);
        if(n==0) return 0;
        for(int i=0; i<n; i++) {
            scanf("%d", &d);
            if(pd == d) continue;
            q.push(d);
            pd = d;
        }
        while(!q.empty()) {
            printf("%d ", q.front());
            q.pop();
        }
        puts("$");
    }
}
