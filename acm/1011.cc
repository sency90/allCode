#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
bool hasAns;
int ans;
void f(int n, int l, int r) {
    if(n==0) return 0;
    f(n-l-r,l+1,r+1);
    f(n-l-r,l+1,r);
    f(n-l-r,l,r+1);
    f(n-l-r,l,r);
    f(n-l,l+1,r+1);
    f(n-l,l,r);

}
int main() {
    int n; scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d", &x,&y);
        hasAns = false;
        ans=0;
        f(y-x,1,1);
    }
    return 0;
}
