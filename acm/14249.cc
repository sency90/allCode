#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
queue<int> q;
int n;
bool valid(int x) { return (x>=0)&&(x<n); }
vector<int> v[100001];
bool chk[100001];
int main() {
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        int x; scanf("%d", &x);
        if(valid(i+x)) v[i].push_back(i+x);
        if(valid(i-x)) v[i].push_back(i-x);
    }
    int s; scanf("%d", &s);
    int cnt=1;
    q.push(s-1);
    chk[s-1]=true;
    while(!q.empty()) {
        int sz = q.size();
        for(int i=0; i<sz; i++) {
            int x = q.front(); q.pop();
            for(int y: v[x]) {
                if(chk[y]) continue;
                chk[y]=true;
                q.push(y);
            }
        }
        cnt++;
    }
    printf("%d", cnt);

    return 0;
}
