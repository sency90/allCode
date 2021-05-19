#include <stdio.h>
#include <stack>
using namespace std;
stack<int> s;
int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    while((a%10)!=0 || (b%10)!=0 || (a/10)!=0 || (b/10)!=0) {
        s.push((a%10)+(b%10));
        a/=10; b/=10;
    }
    while(!s.empty()) {
        printf("%d",s.top()); s.pop();
    }
    return 0;
}
