#include <stdio.h>
#include <queue>
using namespace std;
queue<int> q;
int main() {
    int n, cnt=0;
    long long m, s=0, d;
    scanf("%d %lld", &n, &m);
    for(int i=0; i<n; i++) {
        scanf("%lld", &d);
        s += d;
        q.push(d);
        if(s==m) cnt++;
        else if(s > m) {
            while(s > m) {
                s -= q.front();
                q.pop();
            }
            if(s == m) cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
