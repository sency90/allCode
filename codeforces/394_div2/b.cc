#include <cstdio>
using namespace std;
int a[201],b[201];
int main() {
    int n,l;
    scanf("%d%d",&n,&l);
    for(int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        a[i+n]=a[i]+l;
    }
    for(int i=0; i<n; i++) {
        scanf("%d",&b[i]);
        b[i+n]=b[i]+l;
    }
    int lim = 2*n;
    for(int i=0; i+n<lim; i++) {
        for(int j=0; j+n<lim; j++) {
            int d=a[i]-b[j];
            bool good=true;
            for(int k=0; k<n; k++) {
                if(a[i+k]-b[j+k]!=d) {
                    good=false;
                    break;
                }
            }
            if(good) return 0&puts("YES");
        }
    }
    puts("NO");
    return 0;
}
