#include <stdio.h>
#include <stack>
using namespace std;
stack<int> s;
int main() {
    int n, q, r, m = -2;

    scanf("%d", &n);
    if(n==0) printf("0");

    while(n != 0) {
        q = n/m;
        r = n%m;
        if(r == -1) {
            n = ++q;
            s.push(1);
        } else {
            n = q;
            s.push(r);
        }
    }

    while(!s.empty()) {
        printf("%d", s.top());
        s.pop();
    }
    return 0;
}
