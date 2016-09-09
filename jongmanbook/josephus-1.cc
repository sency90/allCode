#include <queue>
#include <iostream>
using namespace std;
queue<int> q;
int main() {
    ios::sync_with_stdio(false);
    int tc; cin >> tc;
    while(tc--) {
        int n,k,u,v;
        cin >> n >> k;
        if(n!=2) {
            for(int i=2; i<=n; i++) q.push(i);
            while(q.size()>2) {
                for(int i=1; i<k; i++) {
                    q.push(q.front());
                    q.pop();
                }
                q.pop();
            }

            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if(u>v) swap(u,v);
        } else {
            u=1; v=2;
        }

        cout << u << " " << v <<"\n";
    }
    return 0;
}
