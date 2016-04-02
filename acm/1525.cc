#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;
map<int, int> mp;
queue<int> q;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int main() {
    char tmp[9];
    int k;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            k = i*3+j;
            scanf("%c ", &tmp[k]);
            if(tmp[k]=='0') tmp[k]='9';
        }
    }

    string o_pzs=tmp, pzs;
    int x, y, nx, ny, idx, cnt=0, p = stoi(o_pzs);
    q.push(p);
    mp[p] = 1;
    while(!q.empty()) {
        int sz = q.size();
        for(int xx=0; xx<sz; xx++) {
            p = q.front(); q.pop();
            if(p == 123456789) {
                printf("%d", cnt);
                return 0;
            }
            o_pzs = to_string(p);
            idx = o_pzs.find('9');
            x = idx/3; y = idx%3;
            for(int i=0; i<4; i++) {
                string pzs = o_pzs;
                nx = x + dx[i];
                ny = y + dy[i];
                if(nx<0||ny<0||nx>=3||ny>=3) continue;
                swap(pzs[idx], pzs[nx*3+ny]);
                int pn = stoi(pzs);
                if(mp.count(pn)!=0) continue;
                mp[pn] = 1;
                q.push(pn);
            }
        } cnt++;
    }
    puts("-1");
    return 0;
}
