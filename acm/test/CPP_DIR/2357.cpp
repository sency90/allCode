#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;
int v[100000], mng[370], mxg[370];
int main() {
    int n, m, a, b;
    memset(mng, 0x3f, sizeof(mng));
    memset(mxg, 0, sizeof(mxg));
    scanf("%d %d", &n, &m);
    int r = sqrt(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        if(mng[i/r] > v[i]) mng[i/r]=v[i];
        if(mxg[i/r] < v[i]) mxg[i/r]=v[i];
    }
    for(int i=0; i<m; i++) {
        scanf("%d %d", &a, &b);
        a--; b--;
        int mx=0, mn=0x3f3f3f3f;
        if((b-a)/r == 0 || ((b-a)/r==1 && a%r!=0)) {
            for(int j=a; j<=b; j++) {
                if(mx < v[j]) mx=v[j];
                if(mn > v[j]) mn=v[j];
            }
        } else {
            while(a%r!=0) {
                if(mx < v[a]) mx = v[a];
                if(mn > v[a]) mn = v[a];
                a++;
            }
            while(a!=(b-b%r)){
                if(mx < mxg[a/r]) mx=mxg[a/r];
                if(mn > mng[a/r]) mn=mng[a/r];
                a+=r;
            }
            while(b%r!=0) {
                if(mx < v[b]) mx=v[b];
                if(mn > v[b]) mn=v[b];
                b--;
            }
            if(mx < v[b]) mx=v[b];
            if(mn > v[b]) mn=v[b];
        }
        printf("%d %d\n", mn, mx);
    }
    return 0;
}
