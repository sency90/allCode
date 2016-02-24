#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;
queue<int> q;
stack<int> s;
int main() {
    int n, sum, t;
    while(true) {
        sum = 1;
        q.push(1);
        scanf("%d", &n);
        if(n == -1) return 0;
        for(int i=2; i*i<=n; i++) {
            if(n%i==0) {
                sum += i;
                q.push(i);

                if(n/i == i) continue;
                t = n/i;
                sum += t;
                s.push(t);
            }
        }
        printf("%d ", n);
        if(sum == n) {
            printf("= ");
            while(!q.empty()) {
                printf("%d", q.front());
                q.pop();
                if(!q.empty() || !s.empty()) printf(" + ");
            }
            while(!s.empty()) {
                printf("%d", s.top());
                s.pop();
                if(!s.empty()) printf(" + ");
            }
            printf("\n");
        } else {
            printf("is NOT perfect.\n");
            while(!q.empty()) q.pop();
            while(!s.empty()) s.pop();
        }
    }
}
