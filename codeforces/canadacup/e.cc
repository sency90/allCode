#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int chk=(1<<18);
int main() {
    int c,n;
    scanf("%d%d",&c,&n);
    bool hasAns=false;
    for(int i=0; i<n; i++) {
        scanf("%d",&d);
        v.push_back(d);
        if(!hasAns) {
            int f=(d&-d);
            if(f!=d) hasAns=true;
        } else 
    }
    sort(v.begin(), v.end());
    int sum=0;
    for(int i=0; i<n; i++) {
        if(!light) {
            if(v[i]!=(1<<i)) light=true;
            else sum+=v[i];
        } else {
            if(c-v[i]>=sum) {
                puts("Greed is good");
                return 0;
            }
        }
    }
    if(!hasAns) puts("Greed is good");
    else 
    return 0;
}
