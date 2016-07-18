#include <stdio.h>
#include <vector>
using namespace std;
struct Coord{
    int x, y;
    Coord() {}
    Coord(int xx, int yy) {x=xx;y=yy;}
    bool operator<(const Coord& rhs) const {
        if(x==rhs.x) return y<rhs.y;
        else return x<rhs.x;
    }
};
vector<Coord> ir, cu, v;
vector<int> vx, vy;
double dx[]={0.5,0.5,-0.5,-0.5}, dy[]={0.5,-0.5,0.5,-0.5};
int main() {
    int testCase, n, kind;
    int x,y,mx=0,cnt;
    setbuf(stdout, NULL);
    scanf("%d", &testCase);
    for(int z=1; z<=testCase; z++) {
        printf("Case #%d\n", z);
        scanf("%d", &n);
        v.clear(); cu.clear(); ir.clear(); v.clear();
        vx.clear(); vy.clear();
        for(int i=0; i<n; i++) {
            scanf("%d%d%d", &x,&y,&kind);
            if(kind) ir.push_back(Coord(x,y));
            else cu.push_back(Coord(x,y));
            vx.push_back(x);
            vy.push_back(y);
        }
        for(int i=0; i<vx.size(); i++) {
            for(int j=0; j<vy.size(); j++) {
                v.push_back(Coord(vx[i],vy[j]));
            }
        }

        double nx, ny;
        mx=0;
        for(int i=0; i<v.size(); i++) {
            for(int w=0; w<4; w++) {
                cnt=0;
                nx=v[i].x+dx[w]; ny=v[i].y+dy[w];
                for(int j=0; j<ir.size(); j++) {
                    if(ir[j].x<nx && ir[j].y>ny) cnt++;
                    if(ir[j].x>nx && ir[j].y<ny) cnt++;
                }
                for(int j=0; j<cu.size(); j++) {
                    if(cu[j].x>nx && cu[j].y>ny) cnt++;
                    if(cu[j].x<nx && cu[j].y<ny) cnt++;
                }
                if(mx < cnt) mx=cnt;
            }
        }
        printf("%d\n", mx);
    }
    return 0;
}
