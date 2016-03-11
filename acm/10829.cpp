#include <stdio.h>
#include <stack>
using namespace std;
stack<long long> s;
int main() {
    long long n;
    scanf("%lld", &n);
    while(n!=0) {
        s.push(n%2);
        n/=2;
    }
    while(!s.empty()) {
        printf("%lld", s.top()); s.pop();
    }
    return 0;
}
