#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
queue<int> q;
stack<char> s;
char op[4] = {'D', 'S', 'L', 'R'};
int command(int x, int op) {
    if(op == 0) return x*2%10000;
    else if(op == 1) {
        if(x==0) return 9999;
        else return --x;
    } else if(op == 2) return (x%1000)*10 + x/1000;
    else return (x/10) + (x%10)*1000;
}
int d[10000];
bool chk[10000];
char w[10000];
int prv[10000];
int main() {
    int t, a, b;
    int now, next;
    scanf("%d", &t);
    while(t--) {
        memset(d, 0x3f, sizeof(d));
        memset(chk, false, sizeof(chk));
        memset(w, 0, sizeof(w));
        memset(prv, -1, sizeof(prv));
        scanf("%d %d", &a, &b);
        q.push(a);
        d[a] = 0;
        chk[a] = true;
        while(!q.empty()) {
            now = q.front(); q.pop();
            for(int i=0; i<4; i++) {
                next = command(now, i);
                if(chk[next]) continue;
                chk[next] = true;
                d[next] = d[now]+1;
                prv[next] = now;
                w[next] = op[i];
                q.push(next);
            }
        }
        while(a!=b) {
            s.push(w[b]);
            b=prv[b];
        }
        while(!s.empty()) {
            putchar(s.top());
            s.pop();
        }
        puts("");
    }
    return 0;
}
