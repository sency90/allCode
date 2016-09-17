#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
set<int> s;
int main() {
    int n,d;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d",&d);
        s.insert(d);
    }
    if(s.size()>3) puts("NO");
    else if(s.size()==3) {
        int i=0, a[4];
        for(auto x : s) a[i++]=x;
        sort(a, a+3);
        if(a[1]-a[0] == a[2]-a[1]) puts("YES");
        else puts("NO");
    } else puts("YES");
    return 0;
}
