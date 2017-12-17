#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;
int v[200001];
deque<int> dq;
int main() {
    int n,m,k; scanf("%d%d%d",&n,&m,&k);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
    }
    sort(v,v+n);
    int cnt=0;
    for(int i=0; i<n; i++) {
        dq.push_back(v[i]);
        while(v[i]-dq.front()>=m) dq.pop_front();
        while(dq.size()>=k) {
            dq.pop_back();
            cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}
