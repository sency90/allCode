#include <stdio.h>
#include <stack>
using namespace std;
stack<int> s;
int a, b, m, d, t, res=0;
int pp(int x) {
    int ret = 1;
    for(int i=0; i<x; i++) ret*=a;
    return ret;
}
int main() {
    scanf("%d %d %d", &a, &b, &m);
    t = m;
    for(int i=0; i<m; i++) {
        scanf("%d", &d);
        res += d*pp(--t);
    }
    while(res!=0) {
        t = res/b;
        s.push(res%b);
        res = t;
    }
    while(!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    return 0;
}
