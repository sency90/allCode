#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector<int> v[2], z;
char s[101];
int main() {
    int a,b,c,m;
    scanf("%d%d%d%d",&a,&b,&c,&m);
    for(int i=0; i<m; i++) {
        int x;
        scanf("%d%s", &x,s);
        if(s[0]=='U') v[0].push_back(x);
        else v[1].push_back(x);
    }
    sort(v[0].begin(), v[0].end());
    sort(v[1].begin(), v[1].end());
    ll sum=0, cnta=0, cntb=0, cntz=0;
    for(int i=0; i<min(a,(int)v[0].size()); i++) {
        sum+=v[0][i];
        cnta++;
    }
    for(int i=0; i<min(b,(int)v[1].size()); i++) {
        sum+=v[1][i];
        cntb++;
    }
    for(int i=cnta; i<v[0].size(); i++) {
        z.push_back(v[0][i]);
    }
    for(int i=cntb; i<v[1].size(); i++) {
        z.push_back(v[1][i]);
    }
    sort(z.begin(), z.end());
    for(int i=0; i<min((int)z.size(),c); i++) {
        sum+=z[i];
        cntz++;
    }
    printf("%lld %lld\n", cnta+cntb+cntz, sum);
    return 0;
}
