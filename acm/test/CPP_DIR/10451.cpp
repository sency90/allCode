#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
vector<short> v[1000];
bool check[1000];
void dfs(short x) {
    check[x] = true;
    for(short i=0; i<v[x].size(); i++) {
        if(check[v[x][i]]) continue;
        dfs(v[x][i]);
    }
}
int main() {
    short T, N; scanf("%hd", &T);
    short d, cnt;
    while(T--) {
        cnt = 0;
        for(short i=0; i<1000; i++) v[i].clear();
        memset(check, false, sizeof(check));
        scanf("%hd", &N);
        for(short i=0; i<N; i++) {
            scanf("%hd", &d);
            v[i].push_back(d-1);
            v[d-1].push_back(i);
        }

        for(short i=0; i<N; i++) {
            if(!check[i]) {
                dfs(i);
                cnt++;
            }
        }
        printf("%hd\n", cnt);
    }
    return 0;
}
