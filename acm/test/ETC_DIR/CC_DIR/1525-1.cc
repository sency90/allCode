#include <set>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
string pz;
set<string> chk;
queue<pair<string, int> > q;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int nine_idx;
int bfs() {
    int cnt=0;
    string ans = "123456789";
    chk.insert(pz);
    q.push(make_pair(pz, nine_idx));
    while(!q.empty()) {
        int sz = q.size();
        for(int z=0; z<sz; z++) {
            pair<string, int> p = q.front(); q.pop();
            if(p.first == ans) return cnt;
            int x = p.second/3, y = p.second%3;
            for(int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if(nx<0||nx>=3||ny<0||ny>=3) continue;
                swap(p.first[nx*3+ny], p.first[p.second]);
                if(chk.count(p.first) == 0) {
                    chk.insert(p.first);
                    if(p.first == ans) return cnt+1;
                    q.push(make_pair(p.first, nx*3+ny));
                }
                swap(p.first[nx*3+ny], p.first[p.second]);
            }
        } cnt++;
    }
    return -1;
}
int main() {
    char d[2];
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            scanf("%s", d);
            if(d[0]=='0') {
                d[0]='9';
                nine_idx=i*3+j;
            } pz += d[0];
        }
    }
    printf("%d\n", bfs());
    return 0;
}
