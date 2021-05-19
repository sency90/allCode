#include <stdio.h>
#include <set>
#include <vector>
using namespace std;
set<int> s;
int d[2000001];
int main() {
    int n, x, t;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&t,&x);
        if(t==1) {
            d[x]++;
            s.insert(x);
        }else {
            for(auto &it : s) {
                if(x-d[it]<=0) {
                    d[it]--;
                    printf("%d\n", it);
                    if(d[it]==0) s.erase(it);
                    break;
                } else x-=d[it];
            }
        }
    }
    return 0;
}
