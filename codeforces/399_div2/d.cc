#include <cstdio>
using namespace std;
typedef long long ll;
int main() {
    int k,q;
    scanf("%d%d",&k,&q);
    double p,base=1/k;
    for(int i=0; i<q; i++) {
        scanf("%lf", &p);
        double m=p/2000, ans=1.0;
        for(int j=1; j<=k; j++) {
            ans*=m;
            if(ans>=base) {
                printf("%d\n", j);
                break;
            }
        }
    }
    return 0;
}
