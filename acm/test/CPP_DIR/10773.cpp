#include <stdio.h>
#include <stack>
using namespace std;
stack<int> s;
int main() {
    int sum=0, d;
    int n; scanf("%d", &n);
    while(n--) {
        scanf("%d", &d);
        if(d==0) {
            if(s.empty()) continue;
            s.pop();
        } else s.push(d);
    }
    while(!s.empty()) {
        sum += s.top(); s.pop();
    }
    printf("%d", sum);
    return 0;
}
