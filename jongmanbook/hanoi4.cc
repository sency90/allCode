#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
vector<vector<int>> v(4, vector<int>());
int n;
int where(int x) {
    for(int i=0; i<4; i++) {
        for(int j=0; j<v[i].size(); j++) {
            if(v[i][j]==x) return i;
        }
    }
    return -1;
}
void residual(int x, int y, int &r1, int &r2) {
    r1=r2=-1;
    for(int i=0; i<4; i++) {
        if(i==x||i==y) continue;
        else if(r1<0) r1=i;
        else r2=i;
    }
}
int f(int tar, int to, int cnt) {
    int from = where(tar), r1,r2;
    residual(from,to,r1,r2);
    if(tar==0) {
        if(from!=to) return 1;
        else return 0;
    }

    int t;
    if(from!=to) t=1;
    else t=0;

    vector<vector<int>> tmp = v;
    int ret1 = f(tar-1,r1,cnt);
    ret1 += f(tar-1,r1,cnt+t);

    v=tmp;
    int ret2 = f(tar-1,r2,cnt);
    ret2 += f(tar-1,r2,cnt+t);

    return min(ret1,ret2);
}
int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        scanf("%d",&n);
        for(int i=0; i<4; i++) {
            int m; scanf("%d",&m);
            for(int j=0; j<m; j++) {
                int t; scanf("%d",&t);
                v[i].push_back(t);
            }
        }
        int tmp = n, tcnt=0;
        for(int x: v[3]) {
            if(x==tmp) {
                tcnt++;
                tmp--;
            } else break;
        }

        if(tcnt!=0) {
            int j=0;
            for(int i=tcnt; i<v[3].size(); i++,j++) {
                v[3][j]=v[3][i];
            }
            v[3].erase(v[3].begin()+j, v[3].end());
        }
        n-=tcnt;
        printf("%d\n", f(n,3,0));
    }
    return 0;
}
