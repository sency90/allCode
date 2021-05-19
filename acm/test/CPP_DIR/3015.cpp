#include <stack>
#include <stdio.h>
#include <utility>
using namespace std;
stack<pair<long long, long long> > s;
long long cnt=0, d;
int main() {
    int n;
    pair<long long, long long> tmp;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%lld", &d);
        tmp = make_pair(d, 1LL);
        while(!s.empty()) {
            if(s.top().first <= d) {
                cnt += s.top().second;
                if(s.top().first == d) {
                    tmp.second += s.top().second;
                }
                s.pop();
            } else break;
        }
        if(!s.empty()) cnt++;
        s.push(tmp);
    }
    printf("%lld", cnt);
    return 0;
}
