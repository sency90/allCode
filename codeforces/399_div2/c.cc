#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int v[100001],mn=0x3f3f3f3f,mx=0;
int main() {
    int n,k,x;
    scanf("%d%d%d",&n,&k,&x);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[i]);
        mn=min(mn,v[i]);
        mx=max(mx,v[i]);
    }
    if(k==0) printf("%d %d\n",mx,mn);
    else {
        sort(v, v+n);
        mn=0x3f3f3f3f; mx=0;
        for(int i=0; i<n; i++) {
            if(i%2==0) v[i]^=x;
            mn=min(mn,v[i]);
            mx=max(mx,v[i]);
        }
        if(k==1) printf("%d %d\n",mx,mn);
        else {
            k%=2;
            sort(v, v+n);
            mn=0x3f3f3f3f; mx=0;
            for(int i=0; i<n; i++) {
                if(i%2==0) v[i]^=x;
                mn=min(mn,v[i]);
                mx=max(mx,v[i]);
            }
            if(k==0) printf("%d %d\n", mx,mn);
            else {
                sort(v, v+n);
                mn=0x3f3f3f3f; mx=0;
                for(int i=0; i<n; i++) {
                    if(i%2==0) v[i]^=x;
                    mn=min(mn,v[i]);
                    mx=max(mx,v[i]);
                }
                printf("%d %d\n", mx,mn);
            }
        }
    }
    return 0;
}
