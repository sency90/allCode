#include <cstdio>
#include <queue>
#include <cstring>
#include <string>
#include <set>
#include <algorithm>
using namespace std;
queue<pair<int,int> > q;
set<int> chk;
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int bfs() {
    int cnt=0;
    while(!q.empty()) {
        int sz = q.size();
        for(int i=0; i<sz; i++) {
            pair<int,int> tmp = q.front(); q.pop();
            int x=tmp.second/3, y=tmp.second%3;
            if(tmp.first == 123456789) return cnt;

            for(int i=0; i<4; i++) {
                int nx=x+dx[i], ny=y+dy[i];
                if(nx<0||ny<0||nx>=3||ny>=3) continue;

                string in = to_string(tmp.first);
                int npos = nx*3+ny;
                swap(in[npos],in[tmp.second]);

                int nd = stoi(in);
                if(chk.count(nd)) continue;
                chk.insert(nd);
                if(nd==123456789) return cnt+1;
                else q.push(make_pair(nd,npos));
            }
        } cnt++;
    }
    return -1;
}
int main() {
    int zpos;
    char in[10];
    for(int i=0; i<9; i++) {
        scanf("%1s", in+i);
        if(in[i]=='0') {
            in[i]='9';
            zpos=i;
        }
    }
    string iin = in;
    int tmp = stoi(iin);
    q.push(make_pair(tmp,zpos));
    chk.insert(tmp);
    printf("%d", bfs());
    return 0;
}
