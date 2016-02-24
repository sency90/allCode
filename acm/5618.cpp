#include <stdio.h>
#include <stack>
#include <algorithm>
using namespace std;
stack<int> s;
bool cmp(int a, int b) {
    return a>b;
}
int gcd(int b, int l) {
    int t = b%l;
    if(t == 0) return l;
    else return gcd(l, t);
}
int main() {
    int d[3], t, n, i;
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &d[i]);
    sort(d, d+n, cmp);
    t = d[0];
    for(i=1; i<n; i++) t = gcd(t, d[i]);
    for(i=1; i*i<=t; i++) {
        if(t%i == 0) {
            printf("%d\n", i);
            s.push(t/i);
        }
    }
    if(i-1 == s.top()) s.pop();
    while(!s.empty()) {
        printf("%d\n", s.top());
        s.pop();
    }
    return 0;
}
