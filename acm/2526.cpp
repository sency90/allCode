#include <stdio.h>
#include <stack>
#include <cstring>
using namespace std;
stack<int> s;
int n, m, cnt=0;
bool chk[1001];
void dfs(int x) {
    if(chk[x]) {
        while(s.top()!=x) {
            s.pop();
            cnt++;
        }
        return;
    }
    s.push(x);
    chk[x] = true;
    dfs(n*x%m);
}
int main() {
    memset(chk, false, sizeof(chk));
    scanf("%d %d", &n, &m);
    s.push(n);
    chk[n] = true;
    dfs(n*n%m);
    printf("%d", cnt+1);
    return 0;
}
