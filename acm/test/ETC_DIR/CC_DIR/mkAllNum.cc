#include <cstdio>
#include <vector>
using namespace std;
int n;
bool chk[101];
void f(int x, vector<int> & v) {
    if(x==0) {
        printf("%lu ", v.size());
        for(int i=0; i<v.size(); i++) {
            printf("%d ", v[i]);
        }
        puts("");
        return;
    }
    for(int i=1; i<=n; i++) {
        if(chk[i]) continue;
        chk[i] = true;
        v.push_back(i);
        f(x-1, v);
        v.pop_back();
        chk[i] = false;
    }
}
int main() {
    scanf("%d",&n);
    vector<int> v;
    f(n,v);
    return 0;
}
