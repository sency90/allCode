#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
queue<int> q;
int main() {
    ll k;
    int n; scanf("%d%lld",&n,&k);
    int mx=0;
    for(int i=0; i<n; i++) {
        int x;
        scanf("%d", &x);
        mx = max(x,mx);
        q.push(x);
    }
    if(k>ll(n)) printf("%d",mx);
    else {
        int cnt=0;
        int winner = q.front(); q.pop();
        while(cnt<k) {
            int x=q.front(); q.pop();
            if(winner<x) {
                cnt=1;
                q.push(winner);
                winner=x;
            } else {
                cnt++;
                q.push(x);
            }
        }
        printf("%d", winner);
    }
    return 0;
}
