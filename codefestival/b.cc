#include <cstdio>
using namespace std;
int v[100001];
bool chk[100001];
int main() {
    int n; scanf("%d",&n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }
    int x, cnt=0;
    for(int i=1; i<100001; i++) {
        if(chk[i]) continue;
        if(v[i]==i) continue;
        x=v[i];
        if(v[x]==i) {
            chk[x]=chk[i]=true;
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}
