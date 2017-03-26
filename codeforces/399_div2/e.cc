#include <cstdio>
using namespace std;
int v[1000001];
int main() {
    int n,x;
    scanf("%d",&n);
    for(int i=0; i<n; i++) scanf("%d", &v[i]);
    if(n%2==1) puts("NO");
    else {
        int cnt=0;
        for(int i=0; i<n; i++) {
            if(v[i]%2==1) cnt++;
        }
        if(cnt&1) puts("YES");
        else puts("NO");
    }
    return 0;
}
