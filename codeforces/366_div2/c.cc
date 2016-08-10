#include <stdio.h>
#include <vector>
using namespace std;
bool chk[300001];
int totalsz=0;
struct App{
    vector<int> con;
    int sz;
    App() : sz(0) {}
    void link(int x) {
        con.push_back(x);
        sz++;
        totalsz++;
    }
    void clear() {
        for(int i=0; i<con.size(); i++) {
            chk[con[i]] = false;
        }
        con.clear();
        totalsz-=sz;
        sz = 0;
    }
}app[300001];
int where[300001];
int main() {
    int n, q, type, x, del=0, cnt=0;
    scanf("%d%d",&n,&q);
    for(int i=1; i<=q; i++) {
        scanf("%d%d",&type,&x);
        if(type==1) {
            cnt++;
            app[x].link(cnt); //app[x]에서 size하나 늘려줘야 함.
            where[cnt]=x;
            chk[cnt]=true;
        } else if(type == 2) {
            app[x].clear();
        } else {
            if(del < x) {
                for(int j=del+1; j<=x; j++) {
                    if(chk[j]) {
                        totalsz--;
                        chk[j]=false;
                        app[where[j]].sz--;
                    }
                }
                del=x;
            }
        }
        printf("%d\n", totalsz);
    }
    return 0;
}
