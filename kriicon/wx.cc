#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
vector<int> v, nv, ans;
int main() {
    int n,k; ll t;
    scanf("%d%d%lld",&n,&k,&t);
    for(int i=0; i<n; i++) {
        int d; scanf("%d", &d);
        v.push_back(d);
    }
    if(k==1) {
        for(int i=0; i<n; i++) {
            printf("%d ", v[i]);
        }
    } else if(k==2) {
        int tmp = t%n;
        for(int i=0; i<n; i++) {
            if(i+tmp<n) printf("%d ", v[i]^v[i+tmp]);
            else printf("%d ", v[i]^v[i+tmp-n]);
        }
    } else if(k==3) {
        int move=t/n, tmp = t%n;
        for(int i=0; i<n; i++) v.push_back(v[i]);
        nv.resize(2*n);
        for(int i=0; i<n; i++) {
            if(i+move<n) nv[i+move]=v[i];
            else nv[i+move-n]=v[i];
        }

        int f=0;
        for(int i=0; i<3; i++) {
            if(i<n) f^=nv[i];
            else f^=nv[i%n];
        }
        printf("f: %d\n", f);
        puts("Test");
        for(int i=0; i<n; i++) {
            printf("%d ", nv[i]);
        } puts("");


        for(int i=0; i<tmp; i++) {
            for(int j=0; j<3; j++) {
                if(i+j<n) f^=nv[i+j];
                else f^=nv[(i+j)%n];
            }
        }
        ans.resize(2*n,0);
        ans[0]=f;

        tmp++;
        for(int i=1; i<n; i++) {
            int t=0;
            for(int j=0; j<3; j++) {
                if(i-1+j<n) t^=nv[i-1+j];
                else t^=nv[(i-1+j)%n];

                if(i+tmp-j<0) {
                    int alpha=i+tmp-j;
                    while(alpha<0) alpha+=n;
                    t^=nv[alpha];
                } else if(i+tmp-j<n) {
                    t^=nv[i+tmp-j];
                    printf("**%d\n", i+tmp-j);
                } else {
                    t^=nv[(i+tmp-j)%n];
                    printf("*%d\n", (i+tmp-j)%n);
                }
            }
            printf("[i]:%d    t: %d\n", i,t);
            ans[i]=ans[i-1]^t;
            printf("ans[%d]=ans[%d]^%d, ans[i]:%d, ans[i-1]:%d\n",i,i-1,t, ans[i], ans[i-1]);
        }

        for(int i=0; i<n; i++) printf("%d ", ans[i]);
    }
    return 0;
}
