#include <cstdio>
#include <vector>
#include <map>
using namespace std;
map<long long, long long> v;
int dx[]={1,1,-1,-1}, dy[]={1,-1,-1,1};
int df(long long &x, long long &y, long long co) {
    x=co>>17;
    y=co&((1LL<<17)-1LL);
}
int f(long long x, long long y) {
    return (x<<17) + y;
}
bool isWhite(long long co) {
    long long x, y;
    df(x,y,co);
    if((x+y)&1LL) return true;
    else return false;
}
bool isWhite(long long x, long long y) {
    if((x+y)&1LL) return true;
    else return false;
}
int main() {
    int r,c,n;
    scanf("%d%d%d",&r,&c,&n);
    long long x,y,w;
    for(int i=0; i<n; i++) {
        scanf("%lld%lld%lld",&x,&y,&w);
        v[f(x,y)]=w;
    }
    bool good=false;
    long long ans=0LL, whiteans=0LL, blackans=0LL;
    for(auto &it : v) {
        df(x,y,it.first);
        for(int i=0; i<4; i++) {
            long long nx=dx[i]+x, ny=dy[i]+y;
            if(nx<=0LL||nx>r||ny<=0LL||ny>c) continue;
            if(v.count(f(nx,ny))) {
                ans=it.second+v[f(nx,ny)];
                good=true;
                break;
            }
        }
        if(good) break;
    }
    if(good) {
        bool hasAns=true;
        for(auto &it : v) {
            df(x,y,it.first);
            for(int i=0; i<4; i++) {
                long long nx=dx[i]+x, ny=dy[i]+y;
                if(nx<=0LL||nx>r||ny<=0LL||ny>c) continue;
                if(v.count(f(nx,ny))) {
                    if(it.second+v[f(nx,ny)]==ans) continue;
                    else {
                        puts("No");
                        return 0;
                    }
                }
            }
        }
        puts("Yes");
        return 0;
    } else {
        for(auto &it : v) {
            df(x,y,it.first);
            for(int i=0; i<4; i++) {
                long long nx=dx[i]+x, ny=dy[i]+y;
                if(nx<=0LL||nx>r||ny<=0LL||ny>c) continue;

                if(v.count(f(nx,ny))) {
                    long long w=v[f(nx,ny)];
                    if(isWhite(f(nx,ny))) {
                        if(!whiteans) whiteans=w;
                        else if(whiteans!=w) {
                            puts("No");
                            return 0;
                        }
                    } else {
                        if(!blackans) blackans=w;
                        else if(blackans!=w) {
                            puts("No");
                            return 0;
                        }
                    }
                }
            }
        }
        puts("Yes");
    }
    return 0;
}
