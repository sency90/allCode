#include <stdio.h>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int g[370], v[100000];
int main() {
    int n, m, a, b;
    memset(g, 0x3f, sizeof(g));
    scanf("%d %d", &n, &m);
    int r = (int)sqrt(n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        if(g[i/r] > v[i]) g[i/r]=v[i];
    }
    for(int i=0; i<m; i++) {
        int mn = 0x3f3f3f3f;
        scanf("%d %d", &a, &b);
        a--; b--;
        int tmp = (b-a)/r;
        if(tmp == 0 || (tmp==1 && a%r!=0)) {
            for(int j=a; j<=b; j++) {
                if(mn > v[j]) mn = v[j];
            }
        } else {
            while(a%r!=0) {
                if(mn > v[a]) mn = v[a];
                a++;
            }
            tmp = b-b%r;
            while(a!=tmp) {
                if(mn > g[a/r]) mn = g[a/r];
                a+=r;
            }
            while(b%r!=0) {
                if(mn > v[b]) mn = v[b];
                b--;
            }
            if(mn > v[b]) mn = v[b];
        }
        printf("%d\n", mn);
    }
    return 0;
}
