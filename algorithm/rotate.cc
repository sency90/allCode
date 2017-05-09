#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> v;
void f(int x, int ans, vector<bool> &chk) {
    if(x==0) {
        for(int i=1; i<chk.size(); i++) {
            printf("%d ", chk[i]?chk[i]:0);
        }
        printf("=> %d\n", ans);
        return;
    }

    chk[x]=true;
    f(x-1,ans+v[x],chk);

    chk[x]=false;
    f(x-1,ans,chk);
}

int main() {
    int n; scanf("%d", &n);
    v.resize(n+1,0);
    for(int i=1; i<=n; i++) {
        scanf("%d", &v[i]);
    }

    vector<bool> chk(n+1, false);
    f(n,0,chk);
    return 0;
}
