#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
bool chk2(int x, int &cnt) {
    if(x==0) return false;
    while(x!=0) {
        if(x%10 == 1) cnt++;
        else return false;
        x/=10;
    }
    return true;
}
bool chk(int x, int i, int &cnt) {
    while(x>=i) {
        if(x%i==1) cnt++;
        else return false;
        x/=i;
    }
    if(x==1) cnt++;
    else return false;
    return true;
}
int main() {
    freopen("b_input.txt","r",stdin);
    freopen("b_output.txt","w",stdout);
    int tc; scanf("%d", &tc);
    for(int z=1; z<=tc; z++) {
        int x; scanf("%d",&x);
        int mx=0, ans=0;
        for(int i=2; i<=x; i++) {
            int cnt=0;
            if(chk(x,i,cnt)) {
                if(cnt>=mx) {
                    mx=cnt;
                    ans=i;
                }
            }
        }
        printf("Case #%d: %d\n",z,ans);
    }
    return 0;
}
