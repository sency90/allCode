#include <stdio.h>
#include <cstdlib>
#include <map>
#include <string>
#include <algorithm>
#include <queue>
#include <cstring>
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

    int intstr, x, y, nx, ny, cnt=0;
    int p = atoi(tmp), idx, nextidx;
    q.push(p);
    mp[p] = 1;
    string str, oristr;
    while(!q.empty()) {
        int sz = q.size();
        for(int xx=0; xx<sz; xx++) {
            p = q.front(); q.pop();
            if(p == 123456789) {
                printf("%d", cnt);
                return 0;
            }
            oristr = to_string(p);
            idx = oristr.find('9');
            x = idx/3;
            y = idx%3;
            for(int i=0; i<4; i++) {
                string str = oristr;
                nx = x + dx[i];
                ny = y + dy[i];
                if(nx<0||ny<0||nx>=3||ny>=3) continue;
                nextidx = nx*3+ny;
                swap(str[idx], str[nextidx]);
                intstr = stoi(str);
                if(mp.count(intstr)!=0) continue;
                mp[intstr] = 1;
                q.push(intstr);
            }
        } cnt++;
    }
    puts("-1");
    return 0;
}
