#include <cstdio>
#include <map>
using namespace std;
map<int,int> cnt;
int v[2001];
int main() {
    int n, m;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        cnt[v[i]]++;
    }
    int k=n/m;

    return 0;
}
