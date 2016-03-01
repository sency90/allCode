#include <stdio.h>
#include <queue>
using namespace std;
queue<int> q;
int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    for(int i=1; i<=m; i++) {
        q.push(i);
    }
    printf("<");
    while(!q.empty()) {
        for(int i=0; i<n-1; i++) {
            q.push(q.front());
            q.pop();
        }
        printf("%d", q.front());
        q.pop();
        if(!q.empty()) printf(", ");
    }
    printf(">");
    return 0;
}
