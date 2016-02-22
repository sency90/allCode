#include <stdio.h>
#include <stack>
using namespace std;
stack<char> s;
int n, b, t;
void chg(int x) {
    if(x>=10) s.push(x+'A'-10);
    else s.push('0'+x);
}
int main() {
    scanf("%d %d", &n, &b);
    for(t=n; (t/=b)!=0; n=t) chg(n%b);
    if(n!=0) chg(n);
    while(!s.empty()) {
        printf("%c", s.top());
        s.pop();
    } return 0;
}
