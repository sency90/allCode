#include <stdio.h>
#include <algorithm>
#include <map>
using namespace std;
map<int, int> coord;
int main() {
    int tc, n,x,y;
    scanf("%d", &tc);
    while(tc--) {
        int ans = 0;
        coord.clear();
        scanf("%d", &n);
        for(int i=0; i<n; i++) {
            scanf("%d%d",&x,&y);
            ans += coord.size();
            map<int, int>::iterator it = coord.lower_bound(x);
            if(coord.empty()) {
                coord[x]=y;
                continue;
            } else if(it == coord.end()) it--;
            else {
                if(y < it->second) continue;
                else {
                    if(it == coord.begin()) {
                        coord[x]=y;
                        continue;
                    } else it--;
                }
            }

            map<int, int>::iterator it2;
            while(y > it->second) {
                it2 = it;
                if(it == coord.begin()) {
                    coord.erase(it);
                    break;
                } else it2--;
                coord.erase(it);
                it = it2;
            }
            coord[x] = y;
        }
        ans+=coord.size();
        printf("%d\n", ans);
    }
    return 0;
}
