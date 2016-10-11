#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
map<int, int> chk;
int v[2][50001], chg[50001];
int main() {
    int n, t=0, ansT;
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
        scanf("%d", &v[t][i]);
        chk[v[t][i]]++;
    }
    for(int z=0; z<30; z++) {
        //bool hasAns=true;
        /*
        for(auto &p : chk) {
            if(p.second<2) {
                hasAns=false;
                break;
            }
        }
        */
        for(int i=0; i<n; i++) {
            if((v[t][i]>>1)==0) continue;
            if(chk.count(v[t][i]>>1)) {
                v[t^1][i]=v[t][i]>>1<<1;
                chk[v[t^1][i]]++;
                chk[v[t][i]>>1]++;
            } else {
                v[t^1][i]=v[t][i]>>1;
                chk[v[t][i]>>1]++;
            }
        }
        t^=1;
    }
    for(auto &p : v[t]) {
        printf("%d ", p);
    }
    puts("");

    return 0;
}
