#include <cstdio>
#include <vector>
using namespace std;
vector<int> remy_up, remy_down, remx_up, remx_down;
bool inc, dec, watagata;
int x[10001],y[10001];
int main() {
    int n,px,py;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d%d",&x[i],&y[i]);
        if(px>=x[i]) {
            if(i&&py!=y[i]) remy_up.push_back(y[i]);
        } else {
            if(i&&py!=y[i]) remy_down.push_back(y[i]);
        }
        if(py>=y[i]) {
            if(i&&px!=x[i]) remx_up.push_back(x[i]);
        } else {
            if(i&&py!=x[i]) remx_down.push_back(x[i]);
        }
        px=x[i]; py=y[i];
    }
    bool warnning=false;
    int lim=remy_down.size();
    for(int z=lim-1; z>=1; z++) {
        for(auto &up: remy_up) {
            if(remy_down[z]>up || up<remy_down[z-1]) {
                if(warnning) {
                    puts("NO");
                    return 0;
                }
                warnning=true;
            }
        }
    }
    warnning=false;
    lim=remx_down.size();
    for(int z=lim-1; z>=1; z++) {
        for(auto &up: remx_up) {
            if(remx_down[z]>up || up<remx_down[z-1]) {
                if(warnning) {
                    puts("NO");
                    return 0;
                }
                warnning=true;
            }
        }
    }

    puts("YES");
    return 0;
}
