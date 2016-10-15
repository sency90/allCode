#include <stdio.h>
int m;
double n,p;
double balance(double c) {
    double bal = n;
    for(int i=0; i<m; i++) {
        bal += bal*p-c;
    }
    return bal;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        scanf("%lf%d%lf",&n,&m,&p);
        p/=1200.0;
        double l=0, r=n+n*p;
        for(int i=0; i<50; i++) {
            double mid = (l+r)/2.0;
            if(balance(mid)<=0) r=mid;
            else l=mid;
        }
        printf("%0.7lf\n",r);
    }
    return 0;
}
