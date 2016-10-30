#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define x1 co[i].first
#define x2 co[j].first
#define xm co[k].first
#define y1 co[i].second
#define y2 co[j].second
#define ym co[k].second
using namespace std;
vector<int> ans;
pair<int,int> co[401];
bool chk[401];
int main() {
    int n,m,s,last;
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            int x;
            scanf("%d", &x);
            if(x==0) continue;
            co[x]=make_pair(i,j);
            last = x;
        }
    }
    int cnt=0;
    for(int i=1,j=s; i<=last&&j<=last; i++,j++) {
        bool good=true;
        for(int k=1; k<=last; k++) {
            if(i==k||k==j) continue;
            double ax=0.0,ay=0.0;
            printf("%d %lf %lf\n",i,ax,ay);
            if((x2-x1)*(xm-x1)>=0&&(y2-y1)*(ym-y1)>=0) {
                if(xm-x1==0) {
                    if(x2==x1) {
                        if(abs(y2-y1)>abs(ym-y1)) {
                            good=false;
                            break;
                        }
                    }
                    continue;
                } else ax=(double)(x2-x1)/(double)(xm-x1);
                if(ym-y1==0) {
                    if(y2==y1) {
                        if(abs(x2-x1)>abs(xm-x1)) {
                            good=false;
                            break;
                        }
                    }
                    continue;
                } else ay=(double)(y2-y1)/(double)(ym-y1);

                if(ax==ay && (ax>1||ax<-1)) {
                    good=false;
                    break;
                }
            }
        }
        if(good) ans.push_back(i);
    }
    printf("%lu\n", ans.size());
    for(int p: ans) printf("%d\n", p);
    return 0;
}
