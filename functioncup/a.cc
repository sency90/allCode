#include <cstdio>
#include <vector>
using namespace std;
vector<int> child[501];
vector<bool> happy;
int main() {
    int n,m,d;
    scanf("%d", &n);
    happy.resize(n+1, true);
    happy[0]=false;
    for(int i=1; i<=n; i++) {
        scanf("%d%d", &m,&d);
        if(m!=0) child[m].push_back(i);
        else happy[i] = false;
        if(d!=0) child[d].push_back(i);
        else happy[i] = false;
    }
    int p, n2;
    scanf("%d", &n2);
    for(int i=0; i<n2; i++) {
        scanf("%d", &p);
        happy[p]=false;
        for(auto &x : child[p]) {
            happy[x]=false;
        }
    }
    int cnt=0;
    for(int i=1; i<=n; i++) {
        if(happy[i]) cnt++;
    }
    printf("%d\n", cnt);
    return 0;
}
