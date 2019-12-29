#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int a[200001];
int main() {
    int tc; scanf("%d",&tc);
    while(tc--) {
        int n,p,k;
        scanf("%d%d%d",&n,&p,&k);
        for(int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        int np = p, ei=-1, oi=-1, ecnt=0, ocnt=0;
        for(int i=0; i<n; i++) {
            if((i&1)==0) { //even
                if(p>=a[i]) {
                    p-=a[i];
                    ei=i;
                    if(i==0) ecnt++;
                    else ecnt+=2;
                }
                else if(np<a[i]) break;
            }
            else {
                if(np>=a[i]) {
                    np-=a[i];
                    oi=i;
                    ocnt+=2;
                }
                else if(p<a[i]) break;
            }
        }
        if(ei+1<n) {
            if(p>=a[ei+1]) {
                p-=a[ei+1];
                ecnt++;
            }
        }
        if(oi+1<n) {
            if(np>=a[oi+1]) {
                np-=a[oi+1];
                ocnt++;
            }
        }

        printf("%d\n", (ecnt>ocnt)?ecnt:ocnt);


    }
    return 0;
}
