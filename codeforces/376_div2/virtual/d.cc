#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int> > v;
int shift[1000001], c;
void add(int l, int r) {
    if(r<0) shift[0]++, shift[c]--;
    else {
        if(l==c) l=0;
        if(l>r) shift[0]++, shift[r]--, shift[l]++;
        else shift[l]++, shift[r]--;
    }
}
int main() {
    int n,m;
    scanf("%d%d",&n,&c);
    v.resize(n, vector<int>());
    for(int i=0; i<n; i++) {
        scanf("%d",&m);
        v[i].resize(m);
        for(int j=0; j<m; j++) {
            scanf("%d", &v[i][j]); v[i][j]--;
        }
    }
    for(int i=1, j; i<n; i++) {
        int lim = min(v[i-1].size(),v[i].size());
        for(j=0; j<lim && v[i-1][j]==v[i][j]; j++);
        if(j==lim) {
            if(v[i-1].size()<=v[i].size()) add(0,-1);
            else return 0&puts("-1");
        } else add(c-v[i-1][j], c-v[i][j]);
    }
    int sum=0;
    for(int i=0; i<c; i++) {
        sum += shift[i];
        if(sum==n-1) return 0&printf("%d",i);
    }
    puts("-1");
    return 0;
}
