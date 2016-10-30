#include <cstdio>
using namespace std;
int v[100001];
int main() {
    int tc;
    scanf("%d",&tc);
    while(tc--) {
        int n,s=0,cur=0;
        scanf("%d",&n);
        for(int i=0; i<n; i++) {
            scanf("%d",&v[i]);
            if((cur^v[i]) >= cur) cur^=v[i];
            for(int j=s; j<i; s=++j) {
                if((cur^v[j]) > cur) cur^=v[j];
                else break;
            }
            if((cur^v[i]) >= cur) cur^=v[i];
            printf("* %d\n", cur);
        }
        /*
           for(int i=s; i<n; i++) {
           if((cur^v[i]) >= cur) cur^=v[i];
           else break;
           }
           */
        printf("%d\n",cur);
    }
    return 0;
}
