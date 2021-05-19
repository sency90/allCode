#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
queue<pair<int,int> > q;
bool chk[1001][501];
int main() {
    int x[3], sum=0, tmp;
    for(int i=0; i<3; i++) {
        scanf("%d", &x[i]);
        sum += x[i];
    }
    if(sum%3!=0) {
        puts("0");
        return 0;
    }
    sort(x, x+3);
    chk[x[0]][x[1]] = true;
    q.push({x[0],x[1]});
    while(!q.empty()) {
        x[0]=q.front().first; x[1]=q.front().second; q.pop();
        x[2]=sum-x[0]-x[1];
        if(x[0]==x[1] && x[1]==x[2]) {
            puts("1");
            return 0;
        }
        sort(x, x+3);
        tmp = x[0]<<1;
        if(!chk[tmp][x[1]-x[0]]) {
            chk[tmp][x[1]-x[0]] = true;
            q.push({tmp, x[1]-x[0]});
        }
        if(!chk[tmp][x[2]-x[0]]) {
            chk[tmp][x[2]-x[0]] = true;
            q.push({tmp, x[2]-x[0]});
        }
    }
    puts("0");
    return 0;
}
