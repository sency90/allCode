#include <iostream>
using namespace std;
char s[10];
int main() {
    int n; scanf("%d", &n);
    long long sum=0LL;
    for(int i=0; i<n; i++) {
        scanf("%s",s);
        if(s[0]=='d') {
            long long x; scanf("%lld", &x);
            sum += x;
        } else printf("%lld\n", sum);
    }
    return 0;
}
