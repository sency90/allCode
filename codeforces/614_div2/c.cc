#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;
int up[100001], down[100001], upex[100005];
set<int> st;
int main() {
    int n, q; scanf("%d%d",&n,&q);
    for(int i=0; i<q; i++) {
        int r,c; scanf("%d%d",&r,&c);
        if(r==1) {
            if(up[c]==0) {
                up[c]++;
                for(int j=max(c-1,1); j<=min(c+1,n); j++) {
                    upex[j]++;
                    if(down[j]>0) st.insert(j);
                }
            }
            else {
                up[c]--;
                for(int j=max(c-1,1); j<=min(c+1,n); j++) {
                    if(--upex[j]==0 && st.count(j)>0) st.erase(j);
                }
            }
        }
        else {
            if(down[c]==0) {
                down[c]++;
                if(upex[c]>0) {
                    st.insert(c);
                }
            }
            else {
                down[c]--;
                if(upex[c]>0) {
                    st.erase(c);
                }
            }
        }
        if(st.empty()) puts("YES");
        else puts("NO");
    }
    return 0;
}
