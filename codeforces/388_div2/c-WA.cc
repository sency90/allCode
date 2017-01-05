#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
queue<int> dq,rq;
char s[200001];
bool chk[200001];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for(int i=0; i<n; i++) {
        if(s[i]=='D') dq.push(i);
        else rq.push(i);
    }

    for(int i=0; !dq.empty() && !rq.empty(); i++) {
        if(i==n) i=0;
        if(chk[i]) continue;
        if(s[i]=='D') {
            chk[rq.front()]=true;
            rq.pop();
        } else {
            chk[dq.front()]=true;
            dq.pop();
        }
    }
    if(rq.size()>0) puts("R");
    else puts("D");
    return 0;
}
