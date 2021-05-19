#include <stdio.h>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
queue<long long> q;
map<unsigned long long, bool> chk;
long long f(long long x) {
    return 2*x+1;
}
long long g(long long x) {
    return 3*x+1;
}
vector<long long> v;
long long mx=0LL;
const long long LIM=(1LL<<63)+1;
int main() {
    freopen("Users/lian/allCode/acm/output3.txt", "w", stdout);
    long long a, cnt=0LL;
    q.push(1);
    while(!q.empty()) {
        a = q.front(); q.pop();
        if(chk.count(a)) continue;
        printf("%lld ",a);
        cnt++;
        if(cnt>1000000) break;
        if(a>LIM) continue;
        q.push(f(a));
        q.push(g(a));
        chk[a] = true;
    }
    return 0;
}
