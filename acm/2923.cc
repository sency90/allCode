#include <algorithm>
#include <cstdio>
using namespace std;
int tmpa[101], tmpb[101], cnta[101], cntb[101];
int main() {
    int n,a,b;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&a,&b);
        cnta[a]++; cntb[b]++;
        for(int j=1; j<=100; j++) {
            tmpa[j]=cnta[j];
            tmpb[j]=cntb[j];
        }
        int pa=100, pb=1, mx=0;
        while(pa>=1 && pb<=100) {
            while(tmpa[pa]==0 && pa>=1) pa--;
            while(tmpb[pb]==0 && pb<=100) pb++;
            if((pa<=0||pb>=101)&& !tmpa[pa] && !tmpb[pb]) break;
            mx = max(mx, pa+pb);
            if(tmpa[pa]>tmpb[pb]) {
                tmpa[pa]-=tmpb[pb];
                tmpb[pb]=0;
            } else {
                tmpb[pb]-=tmpa[pa];
                tmpa[pa]=0;
            }
        }
        printf("%d\n", mx);
    }
    return 0;
}
