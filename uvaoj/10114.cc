#include <iostream>
#include <algorithm>
using namespace std;
int sm[101]; double r[101];
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int month,n;
    double d,o,c;
    while(true) {
        cin >>month >>d>>o>>n;
        if(month<0) break;
        d=min(o/double(month),d);
        c=o;
        int cur=0;
        for(int i=0; i<n; i++) cin >> sm[i] >> r[i];
        sm[n]=month;
        bool hasAns=false;
        for(int i=0,j=0; j<n; j++) {
            for(;sm[j]<=i && i<sm[j+1]; i++) {
                c-=d;
                o*=(1.0-r[j]);
                if(c<o) {
                    if(i==0) puts("1 month");
                    else printf("%d months\n", i);
                    hasAns=true;
                    break;
                }
            }
        }
        if(!hasAns) {
            c-=d;
            o*=(1.0-r[n-1]);
            if(c<o) {
                if(month==1) puts("1 month");
                else printf("%d months\n", month);
            } else puts("0 months");
        }
    }
    return 0;
}
