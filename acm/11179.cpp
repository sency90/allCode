#include <stdio.h>
#include <stack>
using namespace std;
stack<char> s;
int spow(int x, int y) {
    int res = 1;
    for(int i=0; i<y; i++) res *= x;
    return res;
}
int main() {
    int n; scanf("%d", &n);
    int t;
    while((t=n/2) != 0) {
        s.push(n%2);
        n = t;
    }
    if(n!=0) s.push(n%2);
    int i=0, res=0;
    while(!s.empty()) {
        res += s.top()*spow(2, i++);
        s.pop();
    }
    printf("%d", res);
    return 0;
}
