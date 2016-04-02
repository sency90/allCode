#include <stdio.h>
#include <queue>
using namespace std;
queue<int> q;
void cal(int x) {
    int i=0;
    while(x!=0) {
        if(x%2==1) q.push(i);
        i++;
        x/=2;
    }
}
int main() {
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        cal(n);
        while(!q.empty()) {
            printf("%d ", q.front());
            q.pop();
        }
    }
    return 0;
}
