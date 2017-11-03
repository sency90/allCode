#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
char s[100001][2];
int v[100001];
int chk[100001];
queue<int> q;
int main() {
    int n,op; scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%s%d",s[i],&v[i]);

        int prv;
        if(i==0 && s[i][0]!='^') {
            prv=v[i];
            chk[prv]=i;
        } else {
            if(s[i][0]=='|') prv|=v[i];
            else if(s[i][0]=='&') prv&=v[i];
            else prv^=v[i];
        }
        if(!chk[prv]) chk[prv]=i;
        else {

        }
    }
    printf("%lu\n", q.size());
    while(!q.empty()) {
        int x = q.front(); q.pop();
        printf("%c %d\n", s[x][0],v[x]);
    }
    return 0;
}
