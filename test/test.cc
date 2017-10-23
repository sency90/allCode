#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[100001];
queue<int> q;
bool chk[100001];
int main() {
    int cnt=0;

    chk[1]=true;
    q.push(1);
    while(!q.empty()) {
        int sz = q.size();
        for(int z=0; z<sz; z++) {
            int x = q.front(); q.pop();
            for(int y: v[x]) {
                if(chk[y]) continue;
                chk[y]=true;
                q.push(y);
            }
        }
        cnt++;
    }
    return 0;
}
