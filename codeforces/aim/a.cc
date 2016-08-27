#include <cstdio>
using namespace std;
int main() {
    int n,b,d,x,sum=0, cnt=0;
    scanf("%d%d%d",&n,&b,&d);
    for(int i=0; i<n; i++) {
        scanf("%d", &x);
        if(x<=b) {
            sum+=x;
            if(sum>d) {
                sum=0;
                cnt++;
            }
        }
    }
    printf("%d", cnt);
    /*
    if(sum==0) printf("%d", sum);
    else if(sum%d == 0) printf("%d", sum/d-1);
    else printf("%d", sum/d);
    */
    return 0;
}
